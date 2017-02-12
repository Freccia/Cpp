
#include <iostream>
#include <string>
#include <vector>

class Transform 
{
	private :

		int			getNumSize(int N)
		{
			int		i = 0;

			while (N)
			{
				N /= 10;
				++i;
			}
			return (i);
		}

		std::vector<int> splitNumber(int N)
		{
			std::vector<int>	vct(getNumSize(N));
			int					i = 0;

			while (N)
			{
				vct[i++] = N % 10;
				N /= 10;
			}
			return (vct);
		}

		int			reverse(int N)
		{
			int					i = getNumSize(N) - 1;
			int					len = i;
			std::vector<int>	vct = splitNumber(N);
			int					R = 0;

			R += vct[i];
			while (--i >= 0)
			{
				R += vct[i] * (10 * (len - i));
			}
			return (R);
		}

		bool		isPalindrome(int N)
		{
			std::vector<int> vct = splitNumber(N);
			int		size = getNumSize(N) - 1;
			int		i = 0;

			while (i < size)
			{
				/*
				std::cout<< "vct[" << i << "]: " << vct[i];
				std::cout<< " -- ";
				std::cout<< "vct[" << size - i << "]: " << vct[size - i];
				std::endl;
				*/
				if (vct[i] != vct[size])
					return false;
				++i;
				--size;
			}
			return true;
		}


	public :

		int	palindrome(int N)
		{
			int			P;

			P = N;
			if (N > 9)
			{
				while (!isPalindrome(P))
				{
					P += reverse(N);
				}
			}
			return (P);
		}
};

int		main(int ac, char **av)
{
	Transform Palindrome;

	if (ac > 1)
		std::cout << Palindrome.palindrome(atoi(av[1])) << std::endl;
	else
		std::cout << "No input\n" << std::endl;
	return (0);
}
