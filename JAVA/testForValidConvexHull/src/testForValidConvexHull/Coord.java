package testForValidConvexHull;

public class Coord implements Comparable<Coord> {
	int x;
	int y;
	
	public Coord(int first, int second){
		x = first;
		y = second;
	}
	
	public boolean equals(Coord other){
	    if (this.x!=other.x) return false;
	    if (this.y!=other.y) return false;
	    else return true;
	}
	
	@Override
    public int compareTo(Coord other) {
        //let's sort the Coords based on x in ascending order
        //returns a negative integer, zero, or a positive integer as this Coord
        //is less than, equal to, or greater than the other Coord, respectively.
		if(this.x==other.x){
			if(this.y<other.y) return -1;
			if(this.y>other.y) return 1;
			else return 0;
		}
		else if(this.x<other.x){
			return -1;
		}
		else return 1;
		
//        return (this.x - other.x);
    }
 
	
	

}
