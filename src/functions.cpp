#include "../include/functions.h"
#include "../include/KenoBet.h"

namespace fc{
	int open_file(const char *dest,String &data){
		std::ifstream myFile;

		std::string s;
		myFile.open(dest);
		int aux(0);

		if(myFile.is_open()){
			while(!myFile.eof()){
				//std::getline(myFile,data[aux]);
				std::getline(myFile,s);
				data.push_back(std::move(s));
				aux++;
			}
		}else{
			myFile.close();
			return -1;
		}	
		myFile.close();
		return 0;
	}

	void read_bet(String &data,KenoBet &keno){
		std::stringstream iss(data[2]);
		number_type i; 

		while(iss >> i && keno.size()<15){
			
			keno.add_number(i);
		}
	}

	std::vector<float> print_table(std::string tabela){
		std::vector<float> v;
		std::stringstream iss(tabela);
		float i;
		while(iss >> i){
			v.push_back(i);
		}
		
		std::cout<<"\t\t---------+---------\n";
		std::cout<<"\t\t Hits    | Payout  \n";
		std::cout<<"\t\t---------+---------\n";

		for(int i(0);i<v.size();i++){
			std::cout<<"\t\t"<<i<<"        | "<<v[i]<<"\n";
		}

		return v;
	}

	set_of_numbers_type Hits(){
		std::random_device rd;
		std::mt19937 gen(rd());

		set_of_numbers_type v;
		set_of_numbers_type::iterator it;

		std::uniform_int_distribution <> dis(1,80);

		while(v.size()<20){
			int num = dis(gen);

			it=std::find(v.begin(),v.end(),num);

			if(it == v.end()){
				v.push_back(num);
			}
		}

		return v;
	}

	void sort(set_of_numbers_type::iterator first,set_of_numbers_type::iterator last){
	
		number_type d=std::distance(first,last);
		number_type j,aux;
		for(number_type i=1;i<d;i++){
			aux=first[i];
			j=i-1;

			while(j>=0 && first[j]>aux){
				first[j+1]=first[j];
				j--;
			}
			first[j+1]=aux;
		}
	}

	void print(set_of_numbers_type nums){
		for(auto i:nums){
			std::cout<<i<<" ";
		}
	}
}