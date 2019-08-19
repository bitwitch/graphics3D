#include "engine3D.h"

void MultiplyMatrixVector(vec3d &i, vec3d &o, mat4x4 &m)
{
    o.x = i.x * m.m[0][0] + i.y * m.m[1][0] + i.z * m.m[2][0] + m.m[3][0];
    o.y = i.x * m.m[0][1] + i.y * m.m[1][1] + i.z * m.m[2][1] + m.m[3][1];
    o.z = i.x * m.m[0][2] + i.y * m.m[1][2] + i.z * m.m[2][2] + m.m[3][2];
    float w = i.x * m.m[0][3] + i.y * m.m[1][3] + i.z * m.m[2][3] + m.m[3][3];

    if (w != 0.0f)
    {
        o.x /= w; o.y /= w; o.z /= w;
    }
}

class Engine3D : public olc::PixelGameEngine
{
private:
    mesh meshCube;
    mat4x4 matProj;
    vec3d camera;
    f32 theta;

public:
    Engine3D()
    {
        sAppName = "3D Shit";
    }

    bool OnUserCreate() override
    {


        //meshCube.tris = {

		//// SOUTH
		//{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		//{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		//// EAST                                                      
		//{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		//{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		//// NORTH                                                     
		//{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		//{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		//// WEST                                                      
		//{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		//{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		//// TOP                                                       
		//{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		//{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		//// BOTTOM                                                    
		//{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		//{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		//};

        meshCube.LoadFromObjFile("teapot.obj");

        // Projection Matrix
        matProj = MakeProjection(90.0f, (f32)ScreenHeight() / (f32)ScreenWidth(), 0.1f, 1000.0f); 
        return true;    
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        Clear(olc::BLACK);

        theta += 1.0f * fElapsedTime;

        mat4x4 matTrans = MakeTranslation(0.0f, 0.0f, 8.0f);

        mat4x4 matRotZ = MakeRotationZ(theta);
        mat4x4 matRotX = MakeRotationX(theta * 0.5f);

        for (auto tri : meshCube.tris)
        {
            triangle triRotatedZ, triRotatedZX, triTranslated, triProjected;

            MultiplyMatrixVector(tri.p[0], triRotatedZ.p[0], matRotZ);
            MultiplyMatrixVector(tri.p[1], triRotatedZ.p[1], matRotZ);
            MultiplyMatrixVector(tri.p[2], triRotatedZ.p[2], matRotZ);

            MultiplyMatrixVector(triRotatedZ.p[0], triRotatedZX.p[0], matRotX);
            MultiplyMatrixVector(triRotatedZ.p[1], triRotatedZX.p[1], matRotX);
            MultiplyMatrixVector(triRotatedZ.p[2], triRotatedZX.p[2], matRotX);

            // Offset into screen
            MultiplyMatrixVector(triRotatedZX.p[0], triTranslated.p[0], matTrans);
            MultiplyMatrixVector(triRotatedZX.p[1], triTranslated.p[1], matTrans);
            MultiplyMatrixVector(triRotatedZX.p[2], triTranslated.p[2], matTrans);

            //printf("triTranslated v1(%f, %f, %f) v2(%f, %f, %f) v3(%f, %f, %f)\n", triTranslated.p[0].x,triTranslated.p[0].y,triTranslated.p[0].z,triTranslated.p[1].x,triTranslated.p[1].y,triTranslated.p[1].z,triTranslated.p[2].x,triTranslated.p[2].y,triTranslated.p[2].z);

            // Project from 3D -> 2D
            MultiplyMatrixVector(triTranslated.p[0], triProjected.p[0], matProj);
            MultiplyMatrixVector(triTranslated.p[1], triProjected.p[1], matProj);
            MultiplyMatrixVector(triTranslated.p[2], triProjected.p[2], matProj);

            // Scale into view
            triProjected.p[0].x = (triProjected.p[0].x + 1.0f) * 0.5f * (f32)ScreenWidth(); 
            triProjected.p[0].y = (triProjected.p[0].y + 1.0f) * 0.5f * (f32)ScreenHeight(); 
            triProjected.p[1].x = (triProjected.p[1].x + 1.0f) * 0.5f * (f32)ScreenWidth(); 
            triProjected.p[1].y = (triProjected.p[1].y + 1.0f) * 0.5f * (f32)ScreenHeight(); 
            triProjected.p[2].x = (triProjected.p[2].x + 1.0f) * 0.5f * (f32)ScreenWidth(); 
            triProjected.p[2].y = (triProjected.p[2].y + 1.0f) * 0.5f * (f32)ScreenHeight(); 
           
            DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
                triProjected.p[1].x, triProjected.p[1].y,
                triProjected.p[2].x, triProjected.p[2].y,
                olc::WHITE);
        }

        // draw helper axes
		DrawLine(0.0f, 0.0f, 0.0f, 100.0f, olc::BLUE);    // y-axis
		DrawLine(0.0f, 0.0f, 100.0f, 0.0f, olc::GREEN);   // x-axis 
        return true;    
    }

    bool OnUserDestroy() override
    {
        return true;    
    }
};



int main () {

    Engine3D engine;
    if (engine.Construct(800, 600, 1, 1)) {
        engine.Start();
    }
    return 0;
}
