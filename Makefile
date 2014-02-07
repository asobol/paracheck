paracheck:paracheck.cpp
	g++ -g -o $@ $^

clean:
	rm -f paracheck
