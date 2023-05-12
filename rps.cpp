#include <bits/stdc++.h>
using namespace std;

typedef tuple<char, int, int, int> tuples;
typedef vector<tuple<char, int, int, int>> v_list;

int winner(char a, char b) // This function is used to check the winner of the game 0->lose 1->win
{
    if (a == 'P' && b == 'R')
    {
        return 0;
    }
    else if (a == 'R' && b == 'S')
    {
        return 0;
    }
    else if (a == 'S' && b == 'P')
    {
        return 0;
    }
    else if (a == b)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int r, p, s;
    char c;
    v_list input_state_transition;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    int i = 0;
    while (i < n)
    {
        cin >> c >> r >> p >> s;
        input_state_transition.push_back(tuples(c, r, p, s));
        i++;
    }

    v_list output;
    i = 0;
    while (i < n)
    {
        if (get<0>(input_state_transition[i]) == 'R')
        {
            c = 'P';
            r = get<2>(input_state_transition[i]);
            p = (rand() % n) + 1;
            s = (rand() % n) + 1;
            output.push_back(make_tuple(c, r, p, s));
        }
        else if (get<0>(input_state_transition[i]) == 'P')
        {
            c = 'S';
            r = (rand() % n) + 1;
            p = get<3>(input_state_transition[i]);
            s = (rand() % n) + 1;
            output.push_back(make_tuple(c, r, p, s));
        }
        else if (get<0>(input_state_transition[i]) == 'S')
        {
            c = 'R';
            r = (rand() % n) + 1;
            p = (rand() % n) + 1;
            s = get<1>(input_state_transition[i]);
            output.push_back(make_tuple(c, r, p, s));
        }
        i++;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int check = 1;
    int num_loses = 0;
    for (int i = 1; i < n; i++)
    {
        int rock_input = get<1>(input_state_transition[i]), paper_input = get<2>(input_state_transition[i]), scissor_input = get<3>(input_state_transition[i]);
        char input_state = get<0>(input_state_transition[i]);
        char output_state = get<0>(output[0]);
        int rock_output = get<1>(output[0]), paper_output = get<2>(output[0]), scissor_output = get<3>(output[0]);
        int inp, out;
        int prev_inp = i, prev_out = 0;

        if (output_state == 'R')
        {
            inp = rock_input - 1;
        }
        else if (output_state == 'P')
        {
            inp = paper_input - 1;
        }
        else
        {
            inp = scissor_input - 1;
        }


        if (input_state == 'R')
        {
            out = rock_output - 1;
        }
        else if (input_state == 'P')
        {
            out = paper_output - 1;
        }
        else
        {
            out = scissor_output - 1;
        }

        for (long long int j = 0; j < 1000; j++)
        {
            input_state = get<0>(input_state_transition[inp]);
            output_state = get<0>(output[out]);

            prev_inp = inp;
            prev_out = out;

            char prev_input_state = get<0>(input_state_transition[prev_inp]);
            char prev_output_state = get<0>(output[prev_out]);

            rock_input = get<1>(input_state_transition[inp]), paper_input = get<2>(input_state_transition[inp]), scissor_input = get<3>(input_state_transition[inp]);
            rock_output = get<1>(output[out]), paper_output = get<2>(output[out]), scissor_output = get<3>(output[out]);

            if (output_state == 'R')
            {
                inp = rock_input - 1;
            }
            else if (output_state == 'P')
            {
                inp = paper_input - 1;
            }
            else
            {
                inp = scissor_input - 1;
            }


            if (input_state == 'R')
            {
                out = rock_output - 1;
            }
            else if (input_state == 'P')
            {
                out = paper_output - 1;
            }
            else
            {
                out = scissor_output - 1;
            }

            if (winner(prev_input_state, prev_output_state))
            {
                continue; // its a win so we continue with the present state transition
            }
            num_loses++; // number of losses increases

            if (num_loses == check)
            {
                char temp = get<0>(input_state_transition[prev_inp]);
                char temp_c = get<0>(output[prev_out]);

                r = get<1>(output[prev_out]);
                p = get<2>(output[prev_out]);
                s = get<3>(output[prev_out]);

                if (temp == 'R')
                {
                    r = inp + 1;
                }
                else if (temp == 'P')
                {
                    p = inp + 1;
                }
                else
                {
                    s = inp + 1;
                }
                tuples tmp;
                tmp = make_tuple(temp_c, r, p, s);
                output[prev_out].swap(tmp);

                num_loses = 0;
                check += 10;
            }
        }
        num_loses = 0;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << n << endl;
    i = 0;
    while (i < n)
    {
        cout << get<0>(output[i]) << " " << get<1>(output[i]) << " " << get<2>(output[i]) << " " << get<3>(output[i]) << endl;
        i++;
    }
}
