#include "../include/KenoBet.h"
#include "../include/functions.h"


int main(int argc, char const *argv[])
{
	KenoBet keno;//<!The class kenoBet.
	String data;//<!Vector to string with user's file data.
	String tabela;//<! Vector to string with table data.
	const char enTable[15] = "data/table.dat";//<! Name of table file.
	std::vector<float> vet;//<! Vector to float with table data.
	cash_type IC;//<! Variable initial credit.
	int NR;//<! Number of rounds.
	
	if(argc == 1){
		std::cout<<">> File not attached\n";
		return -1;	
	}

	std::cout<<">>> Preparing to read bet file ["<<argv[1]<<"], please wait..."<<std::endl;
	int result=fc::open_file(argv[1],data);

	std::cout<<"--------------------------------------------------------------------\n";

	if(result == 0){
		if(data.size()<3){
			std::cout<<"Invalid file"<<std::endl;
			return -1;
		}else{
			IC=std::stod(data[0]);
			NR=std::stoi(data[1]);

			fc::read_bet(data,keno);
			
			if(keno.set_wage(IC)){
				std::cout<<">>> Bet successfully read!\n";
			}
		}
	}else{
		std::cout<<"File not Found"<<std::endl;
		return -1;
	}

	std::cout<<"\tYou are going to wage a total of $"<<keno.get_wage()<<" dollars.\n";
	std::cout<<"\tGoing for a total of "<<NR<<" rounds, waging $"<<IC/NR<<" per round.\n\n";
	
	std::cout<<"\tYour bet has "<<keno.size()<<" numbers. They are: [ ";
	fc::print(keno.get_spots());
	std::cout<<"]\n";


	result=fc::open_file(enTable,tabela);

	if(result == 0){
		vet = fc::print_table(tabela[keno.size()]);

	}else{
		std::cout<<"Table not Found"<<std::endl;
		return -1;
	}

	std::cout<<"\t\t--------------------------------------------------------------------\n";
	int aux=1;

	while(aux<=NR && keno.get_wage()>0){

		std::cout<<"\t\tThis is round #"<<aux<<" of "<<NR<<", and your wage is $"<<IC/NR<<". Good luck!\n";

		set_of_numbers_type hits=fc::Hits();
		sort(hits.begin(),hits.end());

		
		std::cout<<"\t\tThe hits are: [ ";
		fc::print(hits);
		std::cout<<"]\n\n";

		set_of_numbers_type ResHis=keno.get_hits(hits);

		std::cout<<"\t\tYou hit the following number(s) [ ";
		fc::print(ResHis);

		keno.set_wage(keno.get_wage() - (IC/NR));

		std::cout<<"], a total of "<< ResHis.size() <<" hits out of "<< keno.size() <<" Payout rate is "<< vet[ResHis.size()] <<", thus you came out with: $"<< (IC/NR) * vet[ResHis.size()] <<"\n";
		keno.set_wage(keno.get_wage() + ((IC/NR) * vet[ResHis.size()]));
		std::cout<<"\t\tYour net balance so far is: $"<<keno.get_wage() <<" dollars.\n\n";


		std::cout<<"\t\t--------------------------------------------------------------------\n\n";
		

		aux++;
	}

	std::cout<<">>> End of rounds!\n";
	std::cout<<"--------------------------------------------------------------------\n\n\n";

	std::cout<<"===== SUMMARY ===== \n";
	std::cout<<">>> You spent in this game a total of $"<<IC<<" dollars.\n";
	int Ganhos=keno.get_wage() - IC;

	if(Ganhos > 0){
		std::cout<<">>> Hooray, you won $"<<Ganhos<<" dollars.  See you next time! ;-)\n";
	}else{
		std::cout<<">>> Hooray, you lost $"<<Ganhos<<" dollars.  See you next time! ;-)\n";
	}
	std::cout<<">>> You are leaving the Keno table with $"<<keno.get_wage()<<" dollars.\n";


	return 0;
}