#ifndef LEVELTWO_H_INCLUDED
#define LEVELTWO_H_INCLUDED

int plane_x, plane_y;
int dpx, dpy;
int check = 10;

void movePlane() {
	plane_x -= dpx;
	plane_y -= dpy;

	if (plane_x <= -140)
		plane_x = 1520;
}

double fireball_x, fireball_y;
int dfx, dfy;

void moveFireball() {
	fireball_x -= dfx;
	fireball_y -= dfy;
}

#endif // !LEVELTWO_H_INCLUDED
