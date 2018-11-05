#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

/*__________________________________________________________Controlling sound._____________________________________________________________*/

void controlSound(bool play_sound)
{
	if (play_sound)
	{
		if (menu_option == 0 || (menu_option >= 2 && menu_option <= 5))
		{
			PlaySound("sound\\intro_music.wav", NULL, SND_LOOP | SND_ASYNC); //The soundtrack is "Warrior" by Randy Dominguez.
		}

		else
		{
			PlaySound("sound\\level_one_music.wav", NULL, SND_LOOP | SND_ASYNC); //The soundtrack is "Heroes Never Die" by David Chappell.
		}
	}

	else if (!play_sound)
	{
		PlaySound(0, 0, 0);
	}
}

#endif // !SOUND_H_INCLUDED
