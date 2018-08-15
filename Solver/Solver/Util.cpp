#include "Util.h"

std::vector<std::string> sSplit(std::string s, std::string div)
{
	std::vector<std::string> parseado;

	std::string aux = "";
	std::string aux2 = "";
	int i, j;
	for (i = 0, j = 0; i < s.length(); ++i)
	{
		if (s[i] != div[j])
		{
			aux += s[i];
		}
		else
		{
			aux2 = "";
			for (; j < div.length() && i < s.length() && s[i] == div[j]; ++i, ++j)
				aux2 += s[i];

			if (j == div.length())
			{
				parseado.push_back(aux);
				aux = "";
			}
			else
			{
				aux += aux2;
			}

			--i;
			j = 0;
		}
	}

	parseado.push_back(aux);

	return parseado;
}