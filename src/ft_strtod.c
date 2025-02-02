#include "../headers/minirt.h"

int	validate_number_string(char *str, int *sign, int *decimal_count)
{
	int		i;
	char	prv;

	prv = '\0';
	i = 0;
	while (str[i])
	{
		if (!ft_strchr("0123456789.+-", str[i]))
			return (1);
		if (str[i] == '+' || str[i] == '-')
			*sign += 1;
		if (str[i] == '.')
			*decimal_count += 1;
		prv = str[i];
		i++;
	}
	if (prv == '+' || prv == '-' || \
	prv == '.' || *sign > 1 || *decimal_count > 1)
		return (1);
	return (0);
}

int	string_to_integer_part(char *str, double *result_ptr)
{
	double	result;
	int		i;

	i = 0;
	result = 0.0;
	while (str[i] != '.' && str[i])
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	*result_ptr = result;
	return (i);
}

int	string_to_decimal_part(char *str, double *result_ptr)
{
	double	decimal_multiplier;
	int		i;
	double	decimal_part;

	i = 0;
	decimal_multiplier = 0.1;
	decimal_part = 0.0;
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		decimal_part = decimal_part + (str[i] - '0') * decimal_multiplier;
		decimal_multiplier *= 0.1;
		i++;
	}
	*result_ptr += decimal_part;
	return (i);
}

int	ft_strtod(char *str, double *result_ptr)
{
	double	final_number;
	int		sign;
	int		decimal_count;

	if (!str || !result_ptr)
		return (-1);
	decimal_count = 0;
	sign = 0;
	final_number = 0.0;
	if (validate_number_string(str, &sign, &decimal_count))
		return (-1);
	str = str + string_to_integer_part(str + sign, &final_number);
	if (decimal_count)
		str += string_to_decimal_part(str + decimal_count, &final_number) + decimal_count;
	*result_ptr = final_number;
	if (sign)
		*result_ptr *= -1;
	return (0);
}