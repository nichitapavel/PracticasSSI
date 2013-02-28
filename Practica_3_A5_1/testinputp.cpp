int Key1 [] = {0,0,0,1,0,1,0,0};
	int Key2 [] = {1,1,0,0,1};
	int Key3 [] = {1,0,1,0,1,1};
	int key_position [] = {3,4};
	//cout << sizeof(Key1)/sizeof(int) << endl;
	/*
	for (int i = 0; i < 19; ++i)
	{
		Key1_.push_back(Key1[i]);
	}
	for (int i = 0; i < 22; ++i)
	{
		Key2_.push_back(Key2[i]);
	}
	for (int i = 0; i < 23; ++i)
	{
		Key3_.push_back(Key3[i]);
	}
	*/

	for (int i = 0; i < 8; ++i)
	{
		Key1_.insert(Key1_.begin(), Key1[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		Key2_.insert(Key2_.begin(), Key2[i]);
	}

	for (int i = 0; i < 6; ++i)
	{
		Key3_.insert(Key3_.begin(), Key3[i]);
	}

	for (int i = 0; i < 2; ++i)
	{
		key_position_.push_back(key_position[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		LFSR1_.push_back(LFSR1[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		LFSR2_.push_back(LFSR2[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		LFSR3_.push_back(LFSR3[i]);
	}
/*
	cout << Key1_[3] << " ole" << endl;
	cout << Key2_[3] << " ole"  << endl;
	cout << Key3_[3] << " ole"  << endl;
	*/

	AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa

	int Key1 [] = {1,0,0,1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1};
	int Key2 [] = {0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0};
	int Key3 [] = {1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,1,1,1};
	int key_position [] = {8,10,10};
	int LFSR1 [] = {18,17,16,13,0};
	int LFSR2 [] = {21,20,0};
	int LFSR3 [] = {22,21,20,7,0};

	//cout << sizeof(Key1)/sizeof(int) << endl;
	/*
	for (int i = 0; i < 19; ++i)
	{
		Key1_.push_back(Key1[i]);
	}
	for (int i = 0; i < 22; ++i)
	{
		Key2_.push_back(Key2[i]);
	}
	for (int i = 0; i < 23; ++i)
	{
		Key3_.push_back(Key3[i]);
	}
	*/

	for (int i = 0; i < 19; ++i)
	{
		Key1_.insert(Key1_.begin(), Key1[i]);
	}

	for (int i = 0; i < 22; ++i)
	{
		Key2_.insert(Key2_.begin(), Key2[i]);
	}

	for (int i = 0; i < 23; ++i)
	{
		Key3_.insert(Key3_.begin(), Key3[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		key_position_.push_back(key_position[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		LFSR1_.push_back(LFSR1[i]);
	}

	for (int i = 0; i < 3; ++i)
	{
		LFSR2_.push_back(LFSR2[i]);
	}

	for (int i = 0; i < 5; ++i)
	{
		LFSR3_.push_back(LFSR3[i]);
	}