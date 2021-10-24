#include "libft.h"

static size_t word_count(char const *str, char delim)
{
	int prev_del;
	int i;
	size_t word_cnt;

	prev_del = 1;
	word_cnt = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == delim)
			prev_del = 1;
		else if (prev_del)
			word_cnt++;
		if (str[i] != delim)
			prev_del = 0;
		i++;
	}
	return (word_cnt);
}

static char **ft_free(size_t k, char **arr)
{
	while (k >= 0)
		free(arr[--k]);
	free(*arr);
	return (NULL);
}

static char **make_arr(char **arr, char const *s, char c, size_t cnt_word)
{
	int i;
	size_t k;
	int start_word;

	i = 0;
	k = 0;
	start_word = 0;
	while (k < cnt_word)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			start_word = i;
		while (s[i] && s[i] != c)
			i++;
		arr[k] = ft_substr(s, start_word, (i - start_word));
		if (arr[k] == NULL)
			return (ft_free(k, arr));
		k++;
	}
	arr[k] = NULL;
	return (arr);
}

char **ft_split(char const *s, char c)
{
	size_t count_words;
	char **arr;

	if (s == NULL)
		return (NULL);
	count_words = word_count(s, c);
	arr = (char **) malloc(sizeof(char *) * (count_words + 1));
	if (arr == NULL)
		return (NULL);
	arr = make_arr(arr, s, c, count_words);
	return (arr);
}