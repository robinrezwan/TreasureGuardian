#ifndef LEVELTWO_H_INCLUDED
#define LEVELTWO_H_INCLUDED

/*____________________________________________________Level two codes are here.________________________________________________________*/

//This function runs all the codes for level two.
void levelTwo()
{
	//cout << "Level two codes running!" << endl;

	/*________________________________________________Showing background for level two.________________________________________________*/

	showBackground2();

	/*__________________________________Showing life potion, cecking collision & counting score._______________________________________*/

	if (life_gem2.x % 2 == 0 || life_gem2.x % 3 == 0)
	{
		if (life_gem2.state)
		{
			iShowImage(life_gem2.x, life_gem2.y, life_gem2.dimension_x, life_gem2.dimension_y, life_gem1.image);

			if (checkCollision(player2.x + player2.extended_x, player2.y + player2.extended_y, 140, 90, life_gem2.x, life_gem2.y, 48, 40))
			{
				//cout << "Boom!" << endl;
				life_gem2.state = false;
				player1.life += 10;
			}
		}
	}

	/*________________________________________________Showing characters for level two.________________________________________________*/

	iShowImage(player2.x, player2.y, 160, 160, player2.image_plane[player_plane_index]);

	/*__________________________________________________Showing player's firing._______________________________________________________*/

	if (fire)
	{
		bullet_y = player2.y + 20;
		iShowImage(bullet_x, bullet_y, 20, 10, bullet_image);
		bullet_x += 10;
		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = player2.x + 110;
		}
	}

	/*___________________________________________________Showing enemy for level two.__________________________________________________*/

	showEnemy2();

	/*_________________________________________________Player, Fire and enemy collision._______________________________________________*/

	fireEnemyCollision2();
	playerEnemyCollision2();

	/*__________________________________________________Showing life and score bar.____________________________________________________*/

	iSetColor(255, 0, 0);
	iText(50, 760, "Life: ", GLUT_BITMAP_HELVETICA_18);
	iRectangle(95, 755, 100, 25);
	iFilledRectangle(95, 755, player1.life, 26);

	iText(50, 730, "Score: ", GLUT_BITMAP_HELVETICA_18);
	sprintf(score_string, "%d", player1.score);
	iText(120, 730, score_string, GLUT_BITMAP_HELVETICA_18);
}

#endif // !LEVELTWO_H_INCLUDED
