#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

/*__________________________________________________________Controlling sound._____________________________________________________________*/

void controlSound(bool play_sound)
{
	if (!mute)
	{
		if (play_sound)
		{
			if (menu_option >= 0 && menu_option <= 5)
			{
				PlaySound("sound\\intro_music.wav", NULL, SND_LOOP | SND_ASYNC); //The soundtrack is "Warrior" by Randy Dominguez.
			}

			else if (game_over)
			{
				PlaySound("sound\\game_over_music.wav", NULL, SND_LOOP | SND_ASYNC); //The soundtrack is "Pride and Glory" by Jacqueline Loran.
			}

			else
			{
				PlaySound("sound\\game_music.wav", NULL, SND_LOOP | SND_ASYNC); //The soundtrack is "Heroes Never Die" by David Chappell.
			}
		}

		else
		{
			PlaySound(0, 0, 0);
		}
	}
}

#endif // !SOUND_H_INCLUDED
