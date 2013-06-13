/*facts*/
city(spokane).
city(seattle).
city(portland).
city(eugene).
city(boise).
city(cda).
city(los_angeles).
city(san_diego).
state(idaho).
state(california).
state(washington).
state(oregon).
capital_of(olympia, washington).
capital_of(boise, idaho).
capital_of(salem, oregon).
capital_of(sacremento, california).
country(usa).
state_in_country(california,usa).
state_in_country(idaho, usa).
state_in_country(washington, usa).
state_in_country(oregon, usa).
city_in_state(los_angeles, california).
city_in_state(san_diego, california).
city_in_state(boise, idaho).
city_in_state(cda, idaho).
city_in_state(spokane, washington).
city_in_state(seattle, washington).
city_in_state(portland, oregon).
city_in_state(eugene, oregon).

/*rules*/
city_in_country(X, Z) :- city_in_state(X, Y), state_in_country(Y, Z).
city(X) :- capital_of(X, _).
city_in_state(X,Y) :- capital_of(X, Y).