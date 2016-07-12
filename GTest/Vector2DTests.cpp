#include <gtest\gtest.h>
#include <Math\Vector2D.h>

using namespace Engine;

TEST(Vector2D, Constructor)
{
	Vector2D empty;
	EXPECT_FLOAT_EQ(empty.x, 0.0f);
	EXPECT_FLOAT_EQ(empty.y, 0.0f);
	Vector2D v1(1.0f, 2.0f);
	EXPECT_FLOAT_EQ(v1.x, 1.0f);
	EXPECT_FLOAT_EQ(v1.y, 2.0f);
	Vector2D v2(3.0f, 1.5f);
	EXPECT_FLOAT_EQ(v2.x, 3.0f);
	EXPECT_FLOAT_EQ(v2.y, 1.5f);
	Vector2D v3(0.2f, 3.2f);
	EXPECT_FLOAT_EQ(v3.x, 0.2f);
	EXPECT_FLOAT_EQ(v3.y, 3.2f);
}

TEST(Vector2D, VectorAddition)
{
	Vector2D v1(1.0f, -11.5f);
	Vector2D v2(5.6f, 2.0f);
	Vector2D v3 = v1 + v2;

	EXPECT_FLOAT_EQ((v1.x + v2.x), v3.x);
	EXPECT_FLOAT_EQ((v1.y + v2.y), v3.y);
}

TEST(Vector2D, ScalarMultiplication)
{
	Vector2D v1(1.5f, 1.0f);
	Vector2D v2(2.3f, 1.5f);

	for (unsigned int i = 0; i < 10; i++) {
		Vector2D v3 = v1 * i;
		Vector2D v4 = v2 * i;

		EXPECT_FLOAT_EQ((v1.x * i), v3.x);
		EXPECT_FLOAT_EQ((v1.y * i), v3.y);
		EXPECT_FLOAT_EQ((v2.x * i), v4.x);
		EXPECT_FLOAT_EQ((v2.y * i), v4.y);
	}
}

TEST(Vector2D, VectorMultiplication)
{
	Vector2D v1(1.5f, 1.0f);
	Vector2D v2(2.3f, 1.5f);
	Vector2D v3 = v1 * v2;
	EXPECT_FLOAT_EQ((v1.x * v2.x), v3.x);
	EXPECT_FLOAT_EQ((v1.y * v2.y), v3.y);
}
