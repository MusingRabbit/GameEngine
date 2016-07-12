#pragma once

namespace Engine {

	class __declspec(dllexport) Vector2D
	{
	public:
		Vector2D() : x(0.0f),y(0.0f) {}
		Vector2D(float x, float y) : x(x), y(y) {}
		~Vector2D() {}

		inline Vector2D operator + (const Vector2D& rhs) {
			return Vector2D(x + rhs.x, y + rhs.y);
		}

		inline Vector2D operator * (const float value) {
			return Vector2D(x * value, y * value);
		}

		inline Vector2D operator * (const Vector2D& rhs) {
			return Vector2D(x * rhs.x, y * rhs.y);
		}

		float x, y;
	};
}