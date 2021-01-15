//
// Created by montgomery anderson on 13/12/16.
// With reference and acknowledgements to:
//      http://nehe.gamedev.net/tutorial/freetype_fonts_in_opengl/24001/
//


#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include "core/libs/textlib.h"
#include <glm/glm.hpp>


namespace textlib {

    using std::vector;
    using std::string;


    /**
     * Gets the next power of 2 which is greater than or equal to a given int.
     * @param x
     * @return
     */
    inline int nextPower(int x) {
        int val = 1;
        while (val < x) val <<= 1;
        return val;
    }


    inline void pushScreenCoordinateMatrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
//        gluOrtho2D(viewport[0], viewport[1], viewport[2], viewport[3]);
        glOrtho(viewport[0], viewport[1], viewport[2], viewport[3], -1.f, 1.f);
        glPopAttrib();
    }


    /**
     * Pops the projection matrix without changing the current matrixMode;
     */
    inline void popProjectionMatrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glPopAttrib();
    }


    /**
     * Creates a display list corresponding to a given character and freetype face.
     * @param face              The freetype face.
     * @param ch                The character the display list is generated around.
     * @param displayListBase
     * @param textBase
     */
    void buildDisplayList(FT_Face face, char ch, GLuint displayListBase, GLuint *textBase) {
        // Load the glyph for ch.
        if (FT_Load_Glyph(face, FT_Get_Char_Index(face, ch), FT_LOAD_DEFAULT))
            throw std::runtime_error("FT_Load_Glyph failed");
        //
        FT_Glyph glyph;
        if (FT_Get_Glyph(face->glyph, &glyph))
            throw std::runtime_error("FT_Get_Glyph failed");
        // Convert the glyph to a bitmap
        FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL, 0, 1);
        FT_BitmapGlyph bitmapGlyph = (FT_BitmapGlyph) glyph;
        FT_Bitmap &bitmap = bitmapGlyph->bitmap;

        // Pad the image up to the next power of two.
        int width = nextPower(bitmap.width);
        int height = nextPower(bitmap.rows);
        GLubyte *expandedData = new GLubyte[2 * width * height];
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                expandedData[2 * (j + i * width)] = 255;
                expandedData[2 * (j + i * width) + 1] =
                        (j >= bitmap.width || i >= bitmap.rows) ? (GLubyte) 0 : bitmap.buffer[j + bitmap.width * i];
            }
        }

        glBindTexture(GL_TEXTURE_2D, textBase[ch]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, expandedData);

        delete[] expandedData;

        // Now generate the display list.
        glNewList(displayListBase + ch, GL_COMPILE);
        glBindTexture(GL_TEXTURE_2D, textBase[ch]);

        glPushMatrix();
        glTranslatef(bitmapGlyph->left, 0, 0);
        glTranslatef(0, bitmapGlyph->top - bitmap.rows, 0);
        float x = (float) bitmap.width / (float) width;
        float y = (float) bitmap.rows / (float) height;
        glBegin(GL_QUADS);
            glTexCoord2d(0, 0); glVertex2f(0, bitmap.rows);
            glTexCoord2d(0, y); glVertex2f(0, 0);
            glTexCoord2d(x, y); glVertex2f(bitmap.width, 0);
            glTexCoord2d(x, 0); glVertex2f(bitmap.width, bitmap.rows);
        glEnd();
        glPopMatrix();
        glTranslatef(face->glyph->advance.x >> 6, 0, 0);

        glEndList();
    }


    void FontData::initialise(const char *fname, unsigned int height) {
        this->textures = new GLuint[128];
        this->height = height;

        // Initialise freetype
        FT_Library library;
        if (FT_Init_FreeType(&library))
            throw std::runtime_error("FT_Init_FreeType failed");

        FT_Face face;
        if (FT_New_Face(library, fname, 0, &face))
            throw std::runtime_error("FT_New_Face failed");

        FT_Set_Char_Size(face, height << 6, height << 6, 96, 96);
        // Allocate resources for textures and display lists.
        listBase = glGenLists(128);
        glGenTextures(128, textures);
        for (unsigned char i = 0; i < 128; i++)
            buildDisplayList(face, i, listBase, textures);

        // Discard the face information and the font library.
        FT_Done_Face(face);
        FT_Done_FreeType(library);
    }


    void FontData::clean() {
        glDeleteLists(listBase, 128);
        glDeleteTextures(128, textures);
        delete[] textures;
    }


    void textlib::print(const FontData &ftFont, float x, float y, const char *fmt, ...) {
//        pushScreenCoordinateMatrix();
        GLuint font = ftFont.listBase;
        float height = ftFont.height / 0.63f;
        char text[256];
        va_list argsPtr;

        if (fmt == NULL) *text = 0;
        else {
            va_start(argsPtr, fmt);
            vsprintf(text, fmt, argsPtr);
            va_end(argsPtr);
        }

        const char *startLine = text;
        vector<string> lines;
        for (const char *c = text; *c; c++) {
            if (*c == '\n') {
                string line;
                for (const char *n = startLine; n < c; n++) line.append(1, *n);
                lines.push_back(line);
                startLine = c + 1;
            }
            if (startLine) {
                string line;
                for (const char *n = startLine; n < c; n++) line.append(1, *n);
                lines.push_back(line);
            }
        }

        glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glListBase(font);

        float modelview_matrix[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);


        for(int i=0;i<lines.size();i++) {
            glPushMatrix();
            glLoadIdentity();
//            glTranslatef(x,y-h*i,0);
            glMultMatrixf(modelview_matrix);

            glCallLists(lines[i].length(), GL_UNSIGNED_BYTE, lines[i].c_str());

            glPopMatrix();
        }

        glPopAttrib();

//        pop_projection_matrix();
    }

}