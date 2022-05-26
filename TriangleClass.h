#pragma once

#include <iostream>

namespace CAP{

	struct Vector3D {

		

		float x, y, z;
		Vector3D()
		{
			x = 0, y = 0, z = 0;
		}
		Vector3D(float X, float Y, float Z)
		{
			x = X; y = Y; z = Z;
		}
		float Distanceto(Vector3D vec) { return sqrtf((x - vec.x) * (x - vec.x) + (y - vec.y) * (y - vec.y) + (z - vec.z) * (z - vec.z)); }
		Vector3D operator +(Vector3D vec) { return Vector3D(vec.x + x, vec.y + y, vec.z + z); }
		void operator +=(Vector3D vec) { x = vec.x + x; y = vec.y + y; z = vec.z + z; }
		Vector3D operator *(float a) { return Vector3D(x * a, y * a, z * a); }
		void operator *=(float a) { x = x * a; y = y * a; z = z * a; }
		Vector3D operator - (Vector3D vec) { return Vector3D(x - vec.x, y - vec.y, z - vec.z); }
	};

	class Triangle
	{

		Vector3D Translation[3];


		


		void rotateX(float angle)
		{
			float sinF = sin(angle);
			float cosF = cos(angle);
			for (int i = 0; i < 3; i++)
			{
				float y = Translation[i].y;
				float z = Translation[i].z;

				Translation[i].y = y * cosF - z * sinF;
				Translation[i].z = z * cosF + y * sinF;
			}

		}

		void rotateY(float angle)
		{
			float sinF = sin(angle);
			float cosF = cos(angle);
			for (int i = 0; i < 3; i++)
			{
				float x = Translation[i].x;
				float z = Translation[i].z;

				Translation[i].x = x * cosF + z * sinF;
				Translation[i].z = z * cosF - x * sinF;
			}


		}

		void rotateZ(float angle)
		{
			float sinF = sin(angle);
			float cosF = cos(angle);
			for (int i = 0; i < 3; i++)
			{
				float x = Translation[i].x;
				float y = Translation[i].y;

				Translation[i].x = x * cosF - y * sinF;
				Translation[i].y = y * cosF + x * sinF;

			}

		}

			void Transform()
			{
				for (int i = 0; i < 3; i++)
					corners[i] = center + Translation[i];
			}

	public :


		Vector3D origin;
		Vector3D center;
		Vector3D corners[3];

		void update()
		{
			center = Vector3D((corners[0].x + corners[1].x + corners[2].x) / 3,
				(corners[0].y + corners[1].y + corners[2].y) / 3,
				(corners[0].z + corners[1].z + corners[2].z) / 3);

			for (int i = 0; i < 3; i++)
				Translation[i] = corners[i] - center;

	         
		}


		void move(float x, float y, float z)
		{
			center += Vector3D(x, y, z);
			Transform();
		}
		void resize(float Alfa)
		{
			for (int i = 0; i < 3; i++)
				Translation[i] *= Alfa;
			Transform();
		}

		void rotate(float AlfaX, float AlfaY, float AlfaZ)
		{
			rotateX(AlfaX);
			rotateY(AlfaY);
			rotateZ(AlfaZ);
			Transform();
		}

	};

}