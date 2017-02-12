
class IncompleteBST
{

	public:

		vector<int> binaryRep(unsigned long long num) 
		{
			cout<< "\n Binary Rep start \n";

			vector<int> vBin;

			while (num > 0)
			{
				vBin.insert(vBin.begin(), num % 2);
				num /= 2;
			}

			cout<< "\n Binary Rep end";
			return vBin;
		}

		bool isValidChild(unordered_map<unsigned long long, char>& map, \
				unordered_map<unsigned long long, char>::iterator childItr, \
				unordered_map<unsigned long long, char>::iterator parentItr)
		{
			cout<< "\n Is Valid Child Start \n";

			if (childItr == map.end())
				cout<< "\n Child iterator is null \n";

			if (parentItr == map.end())
				cout<< "\n Parent iterator is null \n";

			vector<int> vChild = binaryRep(childItr->first);
			vector<int> vParent = binaryRep(parentItr->first);

			int i;

			for (i = 0; i < vParent.size(); i++)
			{
				if (vChild[i] != vParent[i])
					break ;
			}

			if (vChild[i] == 1 && childItr->second > parentItr->second)
			{
				cout<< "\n Valid Child if end \n";
				return true;
			}
			else if (vChild [i] == 0 && childItr->second < parentItr->second)
			{
				cout<< "\n Valid Child else if end \n";
				return true;
			}
			else
			{
				cout<< "\n Valid Child else end \n";
				return false;
			}
		}

		bool isBTS(unordered_map<unsigned long long, char>& map)
		{
			cout<< "\n isBST start  \n";

			unordered_map<unsigned long long, char>::iterator it;

			for (it = map.begin(); it != map.end(); it++)
			{
				if (it->first != 1 && it->second != '?')
				{
					unsigned long long num = it->first;
					unordered_map<unsigned long long, char>::iterator resultItr;

					cout<< "\nFinding parent itr for  \n";
					while (num > 1)
					{
						num /= 2;
						resultItr = map.find(num);

						if (resultItr != map.end())
						{
							if (resultItr->second == '?')
								continue;
							else
								break;
						}
					}
				}

				if (it->second != '?' && resultItr->second != '?' && \
						!isValidChild(map, it, resultItr))
				{
					cout<< "\n IsBTS end if \n";
					return false;
				}
			}
			cout<< "\n IsBTS end  \n";
			return true;
		}


		string getValues(unordered_map<unsigned long long,char>& map,\
				unsigned long long missingNum)
		{ 

			cout<<"\ngetValueSStart\n";

			unsigned long long tmp = missingNum;
			unordered_map<unsigned long long,char>::iterator it;

			while(tmp>1)
			{
				tmp/=2;
				it = map.find(tmp);
				if(it != map.end())
					break;
			}

			vector<int> vChild = binaryRep(missingNum);
			vector<int> vParent = binaryRep(it->first);
			int i;

			for ( i =0 ; i < vParent.size() ; i++)
			{
				if(vChild[i] != vParent[i])
					break;
			}

			string strResult="";

			if(vChild[i] == 1)
			{
				for (char ch = it->second+1 ; ch <= 'Z' ; ch++)
					strResult += ch;
			}
			else
			{
				for (char ch = 'A' ; ch <= it->second ; ch++)
					strResult += ch;
			}
			cout<<"\ngetValuesEnd\n";
			return strResult;


		}


		string missingValues( vector<string> tree )
		{
			cout<< "\n Missing Values START \n";
			unordered_map<unsigned long long,char> map;
			int sz = tree.size();
			unsigned long long missingNum = 0;

			for ( int i=0; i < sz; i++)
			{
				vector<string> vTokens;
				split(tree[i],' ',vTokens);

				unsigned long long num = stoull(vTokens[1]);

				map.insert(make_pair(num,vTokens[0][0]));

				if (vTokens[0] == "?")
					missingNum = num;
			}
			if( !isBST(map))
			{
				return "";
			}
			return getValues(map,missingNum);
		}


		void split(const std::string &s, char delim, \
				std::vector<std::string> &elems)
		{
			std::stringstream ss(s);
			std::string item;
			while (std::getline(ss, item, delim))
			{
				elems.push_back(item);
			}

		}
};
