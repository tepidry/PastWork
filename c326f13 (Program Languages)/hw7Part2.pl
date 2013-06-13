/*tracks(name, track_length, album_id).*/
tracks(sangria, 1.0, 1).
tracks(bleach, 2.0, 2).
tracks(number_Three, 3.0, 3).

/*albums(album_id, album_name, recording_label, year, group_id) release year, and a group id.*/
albums(1, forty_to_freedom, skunk_records, 2001, 14).
albums(2, inutero, columbia, 2002, 24).
albums(3, road_to_freedom, virgin, 2003, 34).

/*groups(group_id, group_name).*/
groups(14, sublime).
groups(24, nirvana).
groups(34, ben_harper).

/*artists(artist_id, name).*/
artists(15, brad_knowell).
artists(25, kurt).
artists(35, ben).

/*artists can be members of groups(artist_id, group_id).*/
group_members(15, 14).
group_members(25, 24).
group_members(35, 34).

/*(a).The album titles created by a group.*/
albums_by(Z, X) :- groups(Y, X), albums(_, Z, _, _, Y).

/*(b).The names of group members Z in for an album X.*/
groupmember_for_album(X, Z) :- albums(_, X, _, _, Y), group_members(K, Y), artists(K, Z).

/*(c).The track titles for an album.*/
track_title_for_album(X, Z) :- albums(Y,X,_,_,_), tracks(Z,_,Y).

/*(d).The track titles Z for an artist X.*/
track_title_for_artist(X, Z) :- artists(Y, X), group_members(Y, K), albums(N, _, _, _, K), tracks(Z, _, N).

/*(e).The album titles released by a label in a year.*/
albums_released_by_Label_in_year(Z, R, X) :- albums(_, Z, R, X, _).