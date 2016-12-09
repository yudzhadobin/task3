#include "Garlic.h"



Garlic::Garlic()
{
	init();
}

void Garlic::init()
{
	this->centerX = 500;
	this->centerY = 250;

	List<double>^ normal = gcnew List<double>;
	normal->Add(1);
	normal->Add(1);
	normal->Add(1);
	double alpha = 30 * M_PI / 180;


	for (int i = 0; i < graduses / step_graduses; i++)
	{
		int angle_thata = i * graduses / step_graduses;
		double radian_thata = angle_thata * M_PI / 180;

		for (int j = 0; j < graduses / step_graduses; j++)
		{
			int angle_ghama = j * graduses / step_graduses;
			double radian_ghama = angle_ghama * M_PI / 180;

			List<double>^ point = gcnew List<double>;

			double xc = R * Math::Cos(radian_ghama) * Math::Sin(radian_thata);
			double yc = R * Math::Cos(radian_ghama) * Math::Cos(radian_thata);
			double zc = R * Math::Sin(radian_ghama);

			point->Add(xc * (1 + 0.5 * Math::Sin(2* alpha))); //x

			point->Add(yc * (1 + 0.5 * Math::Sin(2 * alpha))); //y


			if (radian_ghama > 0) {
				point->Add(zc + R * Math::Pow(radian_ghama / 90, 5)); //z
			}
			else {
				point->Add(zc);
			}

			this->local_points->Add(point);
			this->normals->Add(normal);
		}

		if (i > 0) {
			for (int j = 0; j < graduses / step_graduses - 1; j++) {
				int a = (i - 1) * graduses / step_graduses + j;
				int b = a + 1;
				int c = i  * graduses / step_graduses + j;
				int d = c + 1;

				this->sides->Add(gcnew Side(a, b, c));
				this->sides->Add(gcnew Side(c, d, b));

			}
		}
	}

}
