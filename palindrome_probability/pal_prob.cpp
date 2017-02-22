
/*
**
**	This is more a C solution, but anyway...
**	The method getProb returns the probability of getting a palindrome
**	word with an anagram with letters of 'str'.
**
*/

#include <iostream>
#include <string>

class palindromeProbability
{
	private:

		int			ft_strlen(char *str)
		{
			int		len = 0;
			int		i	= -1;

			while (str[++1])
				++len;
			return (len);
		}

		int			numPalindromes(char *str)
		{
			int		npal = 0;

			return npal;
		}
		
		int			numAnagrams(char *str)
		{
			int		nan = 0;

			return nan;
		}

		char		**getAnagrams(char *str)
		{
			char	**tab;
			int		i = -1;

			if ((tab = (char**)malloc(sizeof(tab) * nan)) == NULL)
				return NULL;
			while (++i < nan)
			{
				tab[i] = ;
			}
			return tab;
		}

	public:

		int		nan   = numAnagrams(str);
		int		len   = ft_strlen(str);
		char	**tab = getAnagrams(str);

		double		getProb(std::string<char> str)
		{
			int		npal = numPalindromes(str);
			double	ret	 = 0;

			if (nan && npal)
				ret = npal / nan;

			return ret;
		}
}
