#ifndef LEVELONE_H_INCLUDED
#define LEVELONE_H_INCLUDED

/*____________________________________________________Level one codes are here.________________________________________________________*/

//This function runs all the codes for level one.
void levelOne()
{
	//cout << "Level one codes running!" << endl;

	/*_______________________________________________Showing background for level one._________________________________________________*/

	showBackground1();

	/*________________________________________________Showing characters for level one.________________________________________________*/

	showPlayer1();

	/*__________________________________________________Showing player's firing._______________________________________________________*/

	if (fire && (player1.condition == 0 || player1.condition == 2))
	{
		iShowImage(bullet_x, player1.y + 40, 20, 10, bullet_image);
		bullet_x += 10;
		if (bullet_x > 1520)
		{
			fire = false;
			bullet_x = player1.x + 110;
		}
	}

	if (fire && (player1.condition == 1 || player1.condition == 3))
	{
		iShowImage(bullet_back_x, player1.y + 40, 20, 20, bullet_back_image);
		bullet_back_x -= 10;
		if (bullet_back_x < -20)
		{
			fire = false;
			bullet_back_x = player1.x;
		}
	}

	/*_________________________________Showing life potion, cecking collision & counting life score.___________________________________*/

	if (life_gem1.x % 2 == 0 || life_gem1.x % 3 == 0)
	{
		if (life_gem1.state)
		{
			iShowImage(life_gem1.x, life_gem1.y, life_gem1.dimension_x, life_gem1.dimension_y, life_gem1.image);

			if (checkCollision(player1.x + player1.extended_x, player1.y + player1.extended_y + jumping_height, 80, 130, life_gem1.x, life_gem1.y, 48, 40))
			{
				//cout << "Boom!" << endl;
				life_gem1.state = false;
				player1.life += 10;
			}
		}
	}

	/*_________________________________________________________Showing enemy.__________________________________________________________*/

	showEnemy();

	/*_________________________________________________Player, Fire and enemy collision._______________________________________________*/

	fireEnemyCollision();
	playerEnemyCollision();

	/*__________________________________________________Showing life and score bar.____________________________________________________*/

	iSetColor(255, 0, 0);
	iText(50, 760, "Life: ", GLUT_BITMAP_HELVETICA_18);
	iRectangle(95, 755, 100, 25);
	iFilledRectangle(95, 755, player1.life, 26);

	iText(50, 730, "Score: ", GLUT_BITMAP_HELVETICA_18);
	sprintf(score_string, "%d", player1.score);
	iText(120, 730, score_string, GLUT_BITMAP_HELVETICA_18);

	if (player1.score >= 200)
	{
		level = 2;
		player2.x = 460;
		player2.y = 600;
	}
}

#endif // !LEVELONE_H_INCLUDED
