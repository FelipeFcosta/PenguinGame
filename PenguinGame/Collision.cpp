#include "Collision.h"


bool Collision::IsColliding(Rect& a, Rect& b, float angleOfA, float angleOfB) {
	Vec2 A[] = { Vec2(a.x, a.y + a.h),
				Vec2(a.x + a.w, a.y + a.h),
				Vec2(a.x + a.w, a.y),
				Vec2(a.x, a.y)
	};
	Vec2 B[] = { Vec2(b.x, b.y + b.h),
					Vec2(b.x + b.w, b.y + b.h),
					Vec2(b.x + b.w, b.y),
					Vec2(b.x, b.y)
	};

	for (auto& v : A) {
		v = Vec2::Rotate(v - a.GetCenter(), angleOfA) + a.GetCenter();
	}

	for (auto& v : B) {
		v = Vec2::Rotate(v - b.GetCenter(), angleOfB) + b.GetCenter();
	}

	Vec2 axes[] = { Vec2::Norm(A[0] - A[1]), Vec2::Norm(A[1] - A[2]), Vec2::Norm(B[0] - B[1]), Vec2::Norm(B[1] - B[2]) };

	for (auto& axis : axes) {
		float P[4];

		for (int i = 0; i < 4; ++i) P[i] = Vec2::Dot(A[i], axis);

		float minA = *std::min_element(P, P + 4);
		float maxA = *std::max_element(P, P + 4);

		for (int i = 0; i < 4; ++i) P[i] = Vec2::Dot(B[i], axis);

		float minB = *std::min_element(P, P + 4);
		float maxB = *std::max_element(P, P + 4);

		if (maxA < minB || minA > maxB)
			return false;
	}

	return true;
}

