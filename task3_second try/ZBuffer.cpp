#include "ZBuffer.h"
#include <limits.h>


ZBuffer::ZBuffer(Bitmap^ bm)
{
	scene = gcnew MyMatrix<Color>(bm->Size.Height, bm->Size.Width);
	zBuffer = gcnew MyMatrix<int>(bm->Size.Height, bm->Size.Width);
}

List<List<int>^>^ restereize() {

}

void ZBuffer::Draw(My3DObject^ object)
{
	for (int i = 0; i < object->sides->Count; i++)
	{
		
		Side^ curSide = object->sides[i];

		List<List<int>^>^ curPoints = gcnew List<List<int>^>;

		for (int i = 0; i < curSide->Points->Count; i++)
		{
			curPoints->Add(object->global_points[curSide->Points[i]]);
		}
		//bounding box
			
		
	}
}

