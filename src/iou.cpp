#include <iostream>
#include <vector>
#include <algorithm>

struct bbox {
	int label; 
	int x1, y1; 
	int x2, y2; 

	bbox(){}
	bbox(int _label, int _x1, int _y1, int _x2, int _y2): 
		label(_label), x1(_x1), y1(_y1), x2(_x2), y2(_y2){}
	bbox &operator=(bbox &&rhs) {
		label = rhs.label; 
		x1 = rhs.x1; 
		x2 = rhs.x2; 
		y1 = rhs.y1; 
		y2 = rhs.y2; 

		return *this; 
	}
};

int iou(bbox &b1, bbox &b2) {
	int left = std::max(b1.x1, b2.x1); 
	int right = std::min(b1.x2, b2.x2);

	int top = std::max(b1.y1, b2.y1); 
	int bot = std::min(b1.y2, b2.y2); 

	int width = std::max(0, right - left); 
	int height = std::max(0, bot - top); 

	return width * height; 
}

int main(int argc, char *argv[]) {
	bbox b1, b2; 
	
	b1 = bbox(0, 0, 0, 20, 20); 
	b2 = bbox(0, 15, 15, 25, 25);
	std::cout << iou(b1, b2) << std::endl; 

	b1 = bbox(0, 0, 0, 20, 20);
	b2 = bbox(0, 25, 25, 35, 35);
	std::cout << iou(b1, b2) << std::endl;

	system("pause"); 
	return 0; 
}
