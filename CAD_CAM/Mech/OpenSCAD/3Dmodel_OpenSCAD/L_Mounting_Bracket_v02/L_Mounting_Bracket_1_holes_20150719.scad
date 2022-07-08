$fn=100;
rotate(a=[0,90,0])

union(){

difference() {
  translate([0,-7.5,0]) cube([12,15,3],center=true);
  translate([0,-5,0]) cylinder(r=1.5+0.1,h=3+0.01, center=true);
  translate([-4.5,-1.5,0]) cube([3.01,3.01,3.01],center=true);
  translate([4.5,-1.5,0]) cube([3.01,3.01,3.01],center=true);
}

corner_radius=1;

translate([-3-corner_radius*2,-3+corner_radius*2,0])
{ 
difference(){
  cylinder(r=corner_radius,h=3, center=true);
  translate([-3,-3,-1.6]) cube([6-5-0.01,3-0.01,3.2]);
  }
}


translate([3+corner_radius*2,-3+corner_radius*2,0])
{
difference(){
cylinder(r=corner_radius,h=3, center=true);
translate([-3,-3,-1.6])
cube([6-5-0.01,3-0.01,3.2]);
}
}

translate([0,-13.5,13.5])
rotate(a=[90,0,0]){
difference() {
translate([0,-7.5,0])
cube([12,15,3],center=true);
translate([0,-5,0])
  cylinder(r=1.5+0.1,h=3+0.01, center=true);
translate([-4.5,-1.5,0])
cube([3.01,3.01,3.01],center=true);
translate([4.5,-1.5,0])
cube([3.01,3.01,3.01],center=true);
}

translate([-3,-3,0])
{
difference(){
cylinder(r=3,h=3, center=true);
translate([-3,-3,-1.6])
cube([6-0.01,3-0.01,3.2]);
}
}
/*
translate([3,-3,0])
{
difference(){
  cylinder(r=3,h=3, center=true);
  translate([-3,-3,-1.6]) cube([6-0.01,3-0.01,3.2]);
  }
}
*/
}
hull(){
translate([6,-12-.1,1.5-.1])
rotate(a=[0,0,90])
prism(1, 3.5, 3.5);
translate([-5,-12-.1,1.5-.1])
rotate(a=[0,0,90])
prism(1, 3.5, 3.5);

}
}



module prism(l, w, h) {
	translate([0, l, 0]) rotate( a= [90, 0, 0]) 
	linear_extrude(height = l) polygon(points = [
		[0, 0],
		[w, 0],
		[0, h]
	], paths=[[0,1,2,0]]);
}