
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
			std::vector<int> vct(getNumSize(N));
			int			i = 0;

			while (N)
			{
				vct[i++] = N % 10;
				N /= 10;
			}
			return (vct);
		}

		bool		isPalindrome(int N)
		{
			std::vector<int> vct = splitNumber(N);
			int		size = getNumSize(N);
			int		i = 0;

			while (i < size / 2)
			{
				std::cout<< vct[i] << " -- " << vct[size-i] << std::endl;
				if (vct[i] != vct[size - i])
					return false;
				++i;
			}
			return true;
		}


	public :

		int	palindrome(int N)
		{
			int			P;

			P = N;
			while (isPalindrome(P))
			{
				P += N;
				std::cout<<"P: "<<P<<std::endl;
			}
			return (P);
		}
};

int		main(int ac, char **av)
{
	Transform Palindrome;

	if (ac > 1)
		std::cout<< Palindrome.palindrome(atoi(av[1])) << std::endl;
	return (0);
}
