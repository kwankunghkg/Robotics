$fn=80;

difference() {
translate([0,0,1.5])
  cylinder(r=10,h=3, center=true);
translate([0,0,1.5])
  cylinder(r=1.5+0.1,h=3+0.01, center=true);
translate([0,5,1.5])
  cylinder(r=1.5+0.1,h=3+0.01, center=true);
translate([0,-5,1.5])
  cylinder(r=1.5+0.1,h=3+0.01, center=true);
translate([(13.6/2),0,1.5])
  cylinder(r=1.0+0.1,h=3+0.01, center=true);
translate([-(13.6/2),0,1.5])
  cylinder(r=1.0+0.1,h=3+0.01, center=true);
}

hh=15+0;
hh2=3;
module legs (){
 hull() {
  translate([-13.5,-12,hh/2])
   cylinder(r=2,h=hh, center=true);
  translate([-6,-4,hh2/2])
   cylinder(r=2,h=hh2, center=true);
 }
 hull() {
  translate([13.5,-12,hh/2])
   cylinder(r=2,h=hh, center=true);
  translate([6,-4,hh2/2])
   cylinder(r=2,h=hh2, center=true);
  }
}

difference(){
 legs();
 translate([0,-12.4,7.5])
  cube(size=[25.35,1.2,15+0.01], center=true);
}

//difference(){
//  rotate([90, 0, 0])
//  translate([-10, 5, 11])
//  cylinder(r = 1, h = 5, center = true);
//}