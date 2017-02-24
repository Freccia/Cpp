
/*
**
**	This is more a C solution, but anyway...
**	The method getProb returns the probability of getting a palindrome
**	word with an anagram with letters of 'str'.
**
**	The problem is: given a string what is the probability of getting 
**	a palindrome on an anagram of that string.
**
**	for example the probability for "ahah" is 1/6 = 0.3333
**
*/

#include <iostream>
#include <string>

class palProb
{
	private:

		void		setAlfa()
		{
			int		i = -1;

			while (++i < 26)
				alfa[i] = 0;
		}

		/*
		 *	If there is more than a pivot, no palindromes.
		 */
		int			checkOnePivot()
		{
			int		i = -1;
			int		pivot = 0;

			while (++i < 26)
			{
				if (alfa[i] % 2)
				{
					if (pivot)
						return (1);
					++pivot;
				}
//				std::cout << "alfa[" << i << "]: " << (char)(i + 'a') << " " << alfa[i] << std::endl;
			}
			return (0);
		}

		long		factor(long n)
		{
			int		k = n;

			while (--k > 1)
			{
				n *= k;
			}
			return (n);
		}

		/*
		 *	Count number of occurrencies of a letter and fulfill alfa[26]	
		 */
		void		countLetters(std::string str)
		{
			int		i = -1;
			int		len = str.length();

			while (++i < len)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
				++alfa[str[i] - 'a'];
//				std::cout << "alfa[" << str[i] - 'a' << "]: " << str[i] << " " << alfa[i] << std::endl << std::endl;
			}
		}

		/*
		 *	Get number of possibles anagrams
		 */
		long		getNumAnagrams(std::string str)
		{
			int		i = -1;
			int		len = str.length();
			long	nan = factor(len);

			while (++i < 26)
			{
				if (alfa[i] > 1)
					nan /= factor(alfa[i]);
			}
			return nan;
		}

		/*
		 *	Get number of possibles palindromes
		 */
		long		getNumPalindromes(std::string str)
		{
			int		len = str.length();
			long	npal;

			npal = factor(len / 2);
			return npal;
		}

	public:

		/*
		 *	Each int will represent the number of occurrencies of a character
		 *	For example alfa[4] represents the number of occurencies of the letter 'e' in str
		 */
		int		alfa[26] = {0};

		float		getProb(std::string str)
		{
			float	ret = 0;

			if (str.empty())
				return (0);
			setAlfa();
			countLetters(str);
			if (checkOnePivot())
				return (0);

			long	nan = getNumAnagrams(str);
			long	npal = getNumPalindromes(str);

//			std::cout << "nan: " << nan << std::endl;
//			std::cout << "npal: " << npal << std::endl;
			if (nan != 0)
				ret = (float)npal / (float)nan;
			
			return ret;
		}
};


int			main(int ac, char **av)
{
	palProb	pB;
	int		i = 0;

	while (++i < ac)
	{
		std::cout << "Probability of  " << av[i] << ":" << std::endl << pB.getProb(av[i]) << std::endl;
	}
	return (0);
}
