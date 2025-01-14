#include "push_swap_bonus.h"

char	*my_strchr(const char *s, int c)
{
	char	ch;

	ch = c;
	while (*s && *s != ch)
		s++;
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}

char	*my_strdup(const char *s)
{
	int		i;
	char	*final;

	final = (char *)malloc(sizeof(char) * (my_strlen(s) + 1));
	if (!final)
		return (NULL);
	i = -1;
	while (s[++i])
		final[i] = s[i];
	final[i] = '\0';
	return (final);
}

char	*my_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*new_s;

	if (!s1 && !s2)
		return (NULL);
	new_s = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		new_s[i++] = *s1++;
	while (s2 && *s2)
		new_s[i++] = *s2++;
	new_s[i] = '\0';
	return (new_s);
}
