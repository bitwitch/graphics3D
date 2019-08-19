#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include <fstream>
#include <strstream>

typedef char unsigned u8;
typedef short unsigned u16;
typedef int unsigned u32; 

typedef char i8;
typedef short i16;
typedef int i32; 

typedef float f32;
typedef double f64;

typedef bool b32;

#include "engine_math.h"

struct triangle {
    vec3d p[3];
    i16 col; 
};

struct mesh {
    std::vector<triangle> tris;

    bool LoadFromObjFile(std::string filename)
    {
        
        std::ifstream f(filename);
        if (!f.is_open()) {
            printf("Error: Could not open file %s\n", filename.c_str());
            return false;
        }

        std::vector<vec3d> verts;

        while(!f.eof()) {
            char line[128];
            f.getline(line, 128);

            std::strstream s;
            s << line;

            char junk;

            if (line[0] == 'v') 
            {
                vec3d v;
                s >> junk >> v.x >> v.y >> v.z;
                verts.push_back(v);
            } 
            else if (line[0] == 'f') 
            {
                int f[3];
                s >> junk >> f[0] >> f[1] >> f[2];
                triangle t = {
                    verts[f[0] - 1],
                    verts[f[1] - 1],
                    verts[f[2] - 1]
                };
                tris.push_back(t);
            }


        }
        return true;
    }
};


