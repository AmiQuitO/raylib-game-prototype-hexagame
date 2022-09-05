#pragma once

#include "raylib.h"
#include <cmath>
#include "raymath.h"

const int WORLD_SIZE = 10;
const int WORLD_SCALE = 10;

const int CHUNK_SIZE = 30;

class Chunk{
	private:
		int size = CHUNK_SIZE;
        int angle = 90;
		int x, y;
        Color color = RED;
	public:
		void Draw(int a, int b, Color color){
			DrawPoly({(float)a ,(float)b}, 6, size, angle, color);
		}

        void SetXY(int a, int b){
            this->x = a;
            this->y = b;
        }

        void SetX(int a){
            x = a;
        }
        void SetY(int a){
            y = a;
        }

        int GetX(){
            return x;
        }
        int GetY(){
            return y;
        }
};

Chunk Map[WORLD_SIZE][WORLD_SIZE];

class WorldClass{
    public:
        void DrawMap(){
            float baseX = 100, baseY = GetScreenHeight() - 100;
            float x, y;
            Color c = BLUE;
			for(int i = 0; i < WORLD_SIZE; i++){
                x = baseX;
                y = baseY + (-i * CHUNK_SIZE * sqrt(3)) - 2;
				for(int j = 0; j < WORLD_SIZE; j++){
                    if(j%2 == 0){
                        y -= ((CHUNK_SIZE * sqrt(3))/2);
                        c = RED;
                    }else{
                        y += ((CHUNK_SIZE * sqrt(3))/2);
                        c = BLUE;
                    }
                    Map[i][j].Draw(x, y, c);
                    x += CHUNK_SIZE * 1.5;
				}
			}
		}
        void GenerateMap(){
            for(int i = 0; i < WORLD_SIZE; i++){
                for(int j = 0; j < WORLD_SIZE; j++){
                    Map[i][j].SetXY(i, j);
                }
            }
        }
};

WorldClass World;