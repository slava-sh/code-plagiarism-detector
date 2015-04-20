// e.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, m, i, kolvoob = 0, kolvopet = 0, kolvovas = 0, pet = 0, vas = 0;
long long l1, r1, l2, r2, h[100000], a[100000];
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m >> l1 >> r1 >> l2 >> r2;
	for (i = 0; i < n; i++) {
		cin >> h[i];
		if ((h[i] >= l1) && (h[i] <= r1)) {
			a[i] = a[i] + 1;
		}
		if ((h[i] >= l2) && (h[i] <= r2)) {
			a[i] = a[i] + 2;
		}
	}
	for (i = 0; i < n; i++) {
		if (a[i] == 1) {
			kolvopet++;
		}
		if (a[i] == 2) {
			kolvovas++;
		}
		if (a[i] == 3) {
			kolvoob++;
		}
	}
	if (kolvoob >= m) {
		if (m % 2 == 0) {
			cout << "Draw";
		}
		else {
			cout << "Petya";
		}
	}
	else {
		if (kolvoob % 2 == 0) {
			if ((m - kolvoob) % 2 == 0) {
				if (((m - kolvoob) / 2) >= kolvopet) {
					pet = pet + kolvopet;
				}
				else {
					pet = pet + ((m - kolvoob) / 2);
				}
				if (((m - kolvoob) / 2) >= kolvovas) {
					vas = kolvovas;
				}
				else {
					vas = ((m - kolvoob) / 2);
				}
			}
			else {
				if (((m - kolvoob) / 2) + 1 >= kolvopet) {
					pet = pet + kolvopet;
				}
				else {
					pet = pet + ((m - kolvoob) / 2) + 1;
				}
				if (((m - kolvoob) / 2) >= kolvovas) {
					vas = kolvovas;
				}
				else {
					vas = ((m - kolvoob) / 2);
				}
			}
		}
		else {
			pet++;
			if ((m - kolvoob) % 2 == 0) {
				if (((m - kolvoob) / 2) >= kolvopet) {
					pet = pet + kolvopet;
				}
				else {
					pet = pet + ((m - kolvoob) / 2);
				}
				if (((m - kolvoob) / 2) >= kolvovas) {
					vas = kolvovas;
				}
				else {
					vas = ((m - kolvoob) / 2);
				}
			}
			else {
				if (((m - kolvoob) / 2) >= kolvopet) {
					pet = pet + kolvopet;
				}
				else {
					pet = pet + ((m - kolvoob) / 2);
				}
				if (((m - kolvoob) / 2) + 1 >= kolvovas) {
					vas = kolvovas;
				}
				else {
					vas = ((m - kolvoob) / 2) + 1;
				}
			}
		}
		
		if (pet > vas) {
			cout << "Petya";
		}
		if (pet < vas) {
			cout << "Vasya";
		}
		if (pet == vas) {
			cout << "Draw";
		}
	}
	return 0;
}

