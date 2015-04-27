#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
 
#define inf 1000000007
#define nmax 200010
#define mmax 100010
#define eps 1e-9

int NNN, MMM;
int PPP[] = {239017, 301703};
int MDD[] = {inf, inf + 2};
int HITP[2][nmax];
char SSS[nmax], TTT[nmax];
int dss[2][26], so[2][26], eow[2][26];
int wo23[26], ls2[26];

/*
public class LzmaUtil {
    private LzmaUtil() {
        throw new UnsupportedOperationException();
    }

    public static byte[] compress(byte[] plainBytes) throws IOException {
        InputStream in = new ByteArrayInputStream(plainBytes);
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        Encoder encoder = new Encoder();

        encoder.setDictionarySize(1 << 23);
        encoder.setEndMarkerMode(true);
        encoder.setMatchFinder(Encoder.EMatchFinderTypeBT4);
        encoder.setNumFastBytes(0x20);

        encoder.writeCoderProperties(out);
        long fileSize = plainBytes.length;
        for (int i = 0; i < 8; ++i) {
            //noinspection NumericCastThatLosesPrecision
            out.write((int) (fileSize >>> (8 * i)) & 0xFF);
        }

        encoder.code(in, out, -1, -1, null);

        out.close();
        in.close();

        return out.toByteArray();
    }

    public static byte[] decompress(byte[] compressedBytes) throws IOException {
        InputStream in = new ByteArrayInputStream(compressedBytes);
        ByteArrayOutputStream out = new ByteArrayOutputStream();

        int propertiesSize = 5;
        byte[] properties = new byte[propertiesSize];
        if (in.read(properties, 0, propertiesSize) != propertiesSize) {
            throw new IOException("LZMA-input is too short.");
        }

        Decoder decoder = new Decoder();
        if (!decoder.setDecoderProperties(properties)) {
            throw new IOException("Incorrect stream properties.");
        }

        long outSize = 0;
        for (int i = 0; i < 8; i++) {
            int v = in.read();
            if (v < 0) {
                throw new IOException("Can't read stream size.");
            }
            //noinspection IntegerMultiplicationImplicitCastToLong
            outSize |= (long) v << (8 * i);
        }

        if (!decoder.code(in, out, outSize)) {
            throw new IOException("Error in data stream.");
        }

        out.close();
        in.close();

        return out.toByteArray();
    }
}
*/

int main() {
	scanf("%d%d\n", &NNN, &MMM);
	gets(SSS + 1);
	gets(TTT + 1);
	for(int k = 0; k < 2; ++k) {
        HITP[k][0] = 1;
        for(int i = 1; i < nmax; ++i) {
            HITP[k][i] = 1LL * HITP[k][i - 1] * PPP[k] % MDD[k];
        }
    }
	for(int i = 1; i <= MMM; ++i) {
		for(int k = 0; k < 2; ++k) {
			dss[k][TTT[i] - 'a'] = (dss[k][TTT[i] - 'a'] + HITP[k][i]) % MDD[k];
			eow[k][SSS[i] - 'a'] = (eow[k][SSS[i] - 'a'] + HITP[k][i]) % MDD[k];
			ls2[SSS[i] - 'a']++;
			wo23[TTT[i] - 'a']++;
		}
	}
	vector < int > result;
	int sled[26] = {};
	for(int i = 1; i + MMM - 1 <= NNN; ++i) {
		vector < pair < pair < int, int >, int > > le, ri;
		for(int j = 0; j < 26; ++j) {
			le.pb(mp(mp(eow[0][j], eow[1][j]), j));
			ri.pb(mp(mp(dss[0][j], dss[1][j]), j));
		}
		sort(le.begin(), le.end());
		sort(ri.begin(), ri.end());
		memset(sled, -1, sizeof(sled));
		bool ok = true;
		for(int i = 0; i < 26; ++i) {
			ok &= le[i].fs == ri[i].fs;
		}
		if(ok == true) {
			for(int j = 0; j < 26; ++j) {
				if(ls2[le[j].sd] == 0) continue;
				if(sled[le[j].sd] != -1 && sled[le[j].sd] != ri[j].sd)
					ok = false;
				sled[le[j].sd] = ri[j].sd;
				if(sled[ri[j].sd] != -1 && sled[ri[j].sd] != le[j].sd)
					ok = false;
				sled
                [ri[j].sd] = le[j].sd;
			}
			if(ok == true)
				result.push_back(i);
		}
		for(int k = 0; k < 2; ++k) {
			eow[k][SSS[i] - 'a'] = (eow[k][SSS[i] - 'a'] + MDD[k] - HITP[k][i]) % MDD[k];
			--ls2[SSS[i] - 'a'];
			if(i + MMM <= NNN) {
				eow[k][SSS[i + MMM] - 'a'] = (eow[k][SSS[i + MMM] - 'a'] + HITP[k][i + MMM]) % MDD[k];
				++ls2[SSS[i + MMM] - 'a'];
			}
			for(int j = 0; j < 26; ++j) {
				dss[k][j] = (dss[k][j] * 1LL * PPP[k]) % MDD[k];
			}
		}
	}
	cout << result.size() << "\n";
	for(int i = 0; i < result.size(); ++i) {
		cout << result[i] << (i == result.size() - 1 ? '\n' : ' ');
	}
	getchar(); getchar();
	return 0;
}