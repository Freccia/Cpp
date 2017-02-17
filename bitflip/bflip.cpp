#include <iostream>
#include <string>
#include <vector>

class BitFlipper 
{
	private :

		int		ft_strlen(char *str)
		{
			int		i = -1;

			while (str[++i])
				;
			return (i);
		}

		int		getMin(char *str)
		{
			int		i = -1;

			while (str[++i])
				if (str[i] == '1')
					break;
			return (i);
		}

		int		getMax(char *str)
		{
			int		i = ft_strlen(str);
			
			while (--i >= 0)
				if (str[i] == '1')
					break ;
			return (i);
		}

		int		flip(char **str)
		{
			int		min = getMin(*str);
			int		max = getMax(*str);
			int		i = min;
			int		ret = 0;
			char	*ptr = *str;

			std::cout << "min: " << min << std::endl;
			std::cout << "max: " << max << std::endl;
			while (i <= max)
			{
				if (ptr[i] == '0')
					ptr[i] = '1';
				else if (ptr[i] == '1')
					ptr[i] = '0';
				else
					return (-1);
				++i;
			}
			std::cout << "point: " << ptr << std::endl;
			if (max >= min)
				return (max - min + 1);
			return (0);
		}

		int		resetted(char *str)
		{
			int		i = -1;

			while (str[++i])
				if (str[i] != '0')
					return (1);
			return (0);
		}

	public :

		int		minFlip(char *str)
		{
			int		ret = 0;

			while (resetted(str))
			{
				ret += flip(&str);
				std::cout << str << std::endl;
			}
			return (ret);
		}
};

int		main(int ac, char **av)
{
	BitFlipper bfl;

	if (ac == 2)
		std::cout << bfl.minFlip(av[1]) << std::endl;
	else
		std::cout << "Wrong numer of args" << std::endl;
	return (0);
}
