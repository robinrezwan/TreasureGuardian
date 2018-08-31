#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

//#include "Variables.h"

/*__________________________________________________________Controlling sound._____________________________________________________________*/

void controlSound(bool play_sound, int sound_index)
{
	if (play_sound)
	{
		if (sound_index == 0)
		{
			PlaySound("sound\\intro_music.wav", NULL, SND_LOOP | SND_ASYNC);
		}

		else if (sound_index == 1)
		{
			PlaySound("sound\\level_one_music.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}

	else if (!play_sound)
	{
		PlaySound(0, 0, 0);
	}
}

#endif // !SOUND_H_INCLUDED
