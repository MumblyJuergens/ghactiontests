extends GdUnitTestSuite

func test_woozlewuzzle():
	var tt :=  TestableThingy.new()
	var result := tt.gimme_string()
	assert_str(result).is_equal("Woozle Wuzzle")
