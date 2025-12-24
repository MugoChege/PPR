public class container_with_most_water{
	public static class HeightPoint{
		public int heightPoint1;
		public int heightPoint2;
	}
	
	public static int absolute (int number){
		return ((number < 0) ? (number * -1) : (number * 1));
	}
	
	public static int get_volume (int height1, int height2, int width){
		int height = (height1 < height2) ? (height1) : (height2);
		
		return (height * width);
	}
	
	public static HeightPoint container_points (int [] list){
		int largest_volume = 0;
		HeightPoint nje = new HeightPoint ();
		int len_list = list.length;
		
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
						
						nje.heightPoint1 = a;
						nje.heightPoint2 = b;
					}
				}
			}
		}
		
		return (nje);
	}
	
	public static void main (String [] args){
		int [] height_list = {1,8,6,2,5,4,8,3,7};
		int len_height_list = height_list.length;
		
		HeightPoint height_indices = container_points(height_list);
		
		int height1 = height_list[height_indices.heightPoint1];
		int height2 = height_list[height_indices.heightPoint2];
		
		int interval = absolute(height_indices.heightPoint1 - height_indices.heightPoint2);
		
		System.out.println("This is the handy work of Java\n\n");
		
		System.out.println(String.format("[%d, %d]\n\n", height_indices.heightPoint1, height_indices.heightPoint2));
		
		System.out.println(String.format("The heights given the points are: %d on one end and %d on the other end. The difference between the two points is %d giving a total volume of %d\n\n", height1, height2, interval, get_volume (height1, height2, interval)));
	}
}
