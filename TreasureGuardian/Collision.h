#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

/*____________________________________________Checking if collision is happenning or not.______________________________________________*/

bool current_collision = false;
bool last_collision = false;

/*This function checks if collision happened or not between two objects or characters and returns a bolean value.
It takes two objects' co-ordinates and dimensions as parameters.*/
bool checkCollision(int object1_x, int object1_y, int dim1_x, int dim1_y, int object2_x, int object2_y, int dim2_x, int dim2_y)
{
	current_collision = (object1_x >= object2_x && object1_x <= object2_x + dim2_x || object1_x + dim1_x >= object2_x && object1_x + dim1_x <= object2_x + dim2_x || object1_x <= object2_x && object1_x + dim1_x >= object2_x + dim2_x) &&
		(object1_y >= object2_y && object1_y <= object2_y + dim2_y || object1_y + dim1_y >= object2_y && object1_y + dim1_y <= object2_y + dim2_y || object1_y <= object2_y && object1_y + dim1_y >= object2_y + dim2_y);

	if (!last_collision && current_collision)
	{
		//cout << "True!" << endl;
		last_collision = current_collision;
		return true;
	}

	/*else if (last_collision && current_collision)
	{
		return false;
	}*/

	else if (last_collision && !current_collision)
	{
		//cout << "False!" << endl;
		last_collision = current_collision;
		return false;
	}

	/*else if (!last_collision && !current_collision)
	{
		return false;
	}*/

	else
	{
		//cout << object1_x << " " << object1_y << " " << dim1_x << " " << dim1_y << " " << object2_x << " " << object2_y << " " << dim2_x << " " << dim2_y << endl;
		return false;
	}
}

#endif // !COLLISION_H_INCLUDED
