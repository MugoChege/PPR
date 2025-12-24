#include <iostream>

using namespace std;

struct HeightValues{
	int height1;
	int height2;
};


struct HeightPoint{
	int heightPoint1;
	int heightPoint2;
	
	/*
	HeightPoint (int h1, int h2){
		heightPoint1 = h1;
		heightPoint2 = h1;
	}
	*/
	//get the points
};

int absolute (int number){
	return (number < 0) ? (number * -1) : (number * 1);
}

int get_volume (int height1, int height2, int width){
	int height = (height1 < height2) ? (height1) : (height2);
	
	return (height * width);
}

HeightPoint container_points(int* list, int len_list){
	int largest_volume = 0;
	HeightPoint out;
	
	for (int a = 0; a < len_list; a++){
		for (int b = (len_list - 1); b > 0; b--){
			if (a == b){
				continue;
			} else if (b < a){
				break;
			} else {
				int interval = absolute(a - b);
				int volume = get_volume (list[a], list[b], interval);
				
				if (largest_volume < volume){
					largest_volume = volume;
					
					out.heightPoint1 = a;
					out.heightPoint2 = b;
				}
			}
		}
	}
	
	return (out);
}

int main () {
	int height_list[] = {1,8,6,2,5,4,8,3,7};
	int len_height_list = sizeof(height_list) / sizeof(height_list[0]);
	
	HeightPoint height_indices = container_points(height_list, len_height_list);
	
	int height1 = height_list[height_indices.heightPoint1];
	int height2 = height_list[height_indices.heightPoint2];
	
	int interval = absolute(height_indices.heightPoint1 - height_indices.heightPoint2);
	
	cout << "This is the handy work of C++" << endl;
	
	cout << "[" << height_indices.heightPoint1 << "," << height_indices.heightPoint2 << "]\n" << endl << endl;
	
	cout << "The heights given the points are: " << height1 << " on one end and " << height2 << " on the other end. The difference between the two points is " << interval << " giving a total volume of " << get_volume(height1, height2, interval) << "\n\n";
	
	return (0);
	
	
}
