#include <stdio.h>

//this is about to be used...
struct HeightPoints;

typedef struct Height{
	int height1;
	int height2;
	
	int(*functional_height)(struct Height*);
	int(*functional_volume)(struct Height*, int);
} Height;

int func_functional_height (struct Height* self){
	return (self->height1 < self->height2) ? (self->height1) : (self->height2);
}

int func_functional_volume (struct Height* self, int width){
	int height = self->functional_height(self);
	
	return (height * width);
}

void function_placer (struct Height* self){
	self->functional_height = func_functional_height;
	self->functional_volume = func_functional_volume;
}

Height make_Height (int height1, int height2){
	Height out;
	
	function_placer(&out);
	
	out.height1 = height1;
	out.height2 = height2;
	
	return (out);
}
//everything till here

typedef struct {
	int heightPoint1;
	int heightPoint2;
} HeightPoints;


int absolute (int number){
	return (number < 0) ? (number * -1) : (number * 1);
}

int get_volume (int height1, int height2, int width){
	int height = (height1 < height2) ? (height1) : (height2);
	
	return (height * width);
}

HeightPoints container_points(int* list, int len_list){
	int largest_volume = 0;
	HeightPoints out;
	
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
					//out = {a, b};
					out.heightPoint1 = a;
					out.heightPoint2 = b;
				}
			}
		}
	}
	
	return (out);
}

int main (){
	int height_list[] = {1,8,6,2,5,4,8,3,7};
	int len_height_list = sizeof(height_list) / sizeof(height_list[0]);
	HeightPoints height_indices = container_points (height_list, len_height_list);
	int height1 = height_list[height_indices.heightPoint1];
	int height2 = height_list[height_indices.heightPoint2];
	int interval = absolute(height_indices.heightPoint1 - height_indices.heightPoint2);
	
	printf ("This is the handy work of C\n\n");
	
	printf ("[%d, %d]\n\n", height_indices.heightPoint1, height_indices.heightPoint2);
	
	printf ("The heights given the points are: %d on one end and %d on the other end. The difference between the two points is %d giving a total volume of %d\n\n", height1, height2, interval, get_volume (height1, height2, interval));
	
	return (0);
}

