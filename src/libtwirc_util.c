#include <stdio.h>      // NULL, fprintf(), perror()
#include "libtwirc.h"

/*
 * Returns 1 if state is currently connecting to Twitch IRC, otherwise 0.
 */
int twirc_is_connecting(const struct twirc_state *state)
{
	return state->status & TWIRC_STATUS_CONNECTING ? 1 : 0;
}

/*
 * Returns 1 if state is connected to Twitch IRC, otherwise 0.
 */
int twirc_is_connected(const struct twirc_state *state)
{
	return state->status & TWIRC_STATUS_CONNECTED ? 1 : 0;
}

/*
 * Returns 1 if state is currently authenticating, otherwise 0.
 */
int twirc_is_logging_in(const struct twirc_state *state)
{
	return state->status & TWIRC_STATUS_AUTHENTICATING ? 1 : 0;
}

/*
 * Returns 1 if state is authenticated (logged in), otherwise 0.
 */
int twirc_is_logged_in(const struct twirc_state *state)
{
	return state->status & TWIRC_STATUS_AUTHENTICATED ? 1 : 0;
}

/*
 * Return the login struct, which contains login and user data.
 */
struct twirc_login *twirc_get_login(struct twirc_state *state)
{
	return &state->login;
}

/*
 * Searches the provided array of twirc_tag structs for a tag with the 
 * provided key, then returns a pointer to that tag's value.
 */
char *twirc_tag_by_key(struct twirc_tag **tags, const char *key)
{
	for (int i = 0; tags[i] != NULL; ++i)
	{
		if (strcmp(tags[i]->key, key) == 0)
		{
			return tags[i]->value;
		}
	}
	return NULL;
}

/*
 * Return the error code of the last error or -1 if non occurred so far.
 */
int twirc_last_error(const struct twirc_state *state)
{
	return state->error;
}
