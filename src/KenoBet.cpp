#include "../include/KenoBet.h"

bool KenoBet::add_number(number_type spot_){
	if(spot_>=1 && spot_<=80){
	
		set_of_numbers_type::iterator it;

		it=std::find(m_spots.begin(),m_spots.end(),spot_);

		if(it != m_spots.end()){
			return false;
		}else{
			m_spots.push_back(spot_);
			return true;
		}
	}
	return false;
}

bool KenoBet::set_wage(cash_type wage_){
	m_wage = wage_;
	if(wage_ > 0){
		return true;
	}else
		return false;
}

void KenoBet::reset(void){
	m_spots.clear();
}

cash_type KenoBet::get_wage(void)const{
	return m_wage;
}

size_t KenoBet::size(void)const{
	return m_spots.size();
}

set_of_numbers_type KenoBet::get_hits(const set_of_numbers_type &hits)const{
	set_of_numbers_type v;

	for(int i(0);i<size();i++){

		int inf=0;
		int sup=hits.size()-1;
		int meio;

		while(inf<=sup){
			meio=(sup+inf)/2;
			if(m_spots[i]==hits[meio]){
				v.push_back(m_spots[i]);
				break;

			}else if(m_spots[i]<hits[meio]){
				sup=meio-1;
			}else {
				inf=meio+1;
			}
		}
	}

	return v;
}

set_of_numbers_type KenoBet::get_spots(void) const{
	
	return m_spots;
}