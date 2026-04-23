If you want it more scalable

Put all cases in an array and loop:

int costs[4];

costs[0] = max(nrotcost(q, bk), nrotcost(q, ak));
costs[1] = max(protcost(q, bk), protcost(q, ak));
costs[2] = nrotcost(q, bk) + protcost(q, ak);
costs[3] = protcost(q, bk) + nrotcost(q, ak);

int best = costs[0];
for (int i = 1; i < 4; i++)
{
    if (costs[i] < best)
        best = costs[i];
}
⚡ Key idea

You're not just comparing numbers—you’re comparing strategies:

same rotation → max
different rotation → sum
final decision → min

If you want, I can help you turn this into a function that also tells you which strategy to execute (not just the cost).

and then how do i recognize which strategy won out of them

Good question—that’s the missing piece: you don’t just want the best cost, you also want to know which strategy produced it so you can execute the right moves.

✅ Solution: track the index (or use an enum)
Step 1: define strategies clearly
enum e_strategy
{
    RR,     // both rotate up
    RRR,    // both rotate down
    RA_RRB, // a up, b down
    RB_RRA  // b up, a down
};
Step 2: compute costs in parallel
int costs[4];

costs[RR]     = max(nrotcost(q, bk), nrotcost(q, ak));
costs[RRR]    = max(protcost(q, bk), protcost(q, ak));
costs[RA_RRB] = nrotcost(q, bk) + protcost(q, ak);
costs[RB_RRA] = protcost(q, bk) + nrotcost(q, ak);
Step 3: find best strategy AND cost
int best = costs[0];
int best_strategy = 0;

for (int i = 1; i < 4; i++)
{
    if (costs[i] < best)
    {
        best = costs[i];
        best_strategy = i;
    }
}
Step 4: use the result
if (best_strategy == RR)
{
    // do rr rotations
}
else if (best_strategy == RRR)
{
    // do rrr rotations
}
else if (best_strategy == RA_RRB)
{
    // do ra + rrb
}
else if (best_strategy == RB_RRA)
{
    // do rb + rra
}
🧠 Even cleaner (optional)

Use a struct to bundle everything:

typedef struct s_move
{
    int cost;
    int strategy;
} t_move;

But honestly, the array + enum approach is already clean and very common in C.

⚡ Key idea

You’re not just computing values—you’re keeping a mapping:

index → meaning → cost

So when you find the minimum, you automatically know what it represents.

If you want, I can help you map each strategy directly into the exact sequence of operations (rr, rra, etc.) so your code becomes almost plug-and-play.

how to get an int array[4] from a function and send it to another function

In C you can’t return an array directly, but there are a few clean ways to achieve what you want.

✅ 1. Best practice: pass the array as an argument (recommended)

You create the array in the caller and let the function fill it.

void compute_costs(int costs[4], t_q *q, int ak, int bk)
{
    costs[0] = max(nrotcost(q, bk), nrotcost(q, ak));
    costs[1] = max(protcost(q, bk), protcost(q, ak));
    costs[2] = nrotcost(q, bk) + protcost(q, ak);
    costs[3] = protcost(q, bk) + nrotcost(q, ak);
}

Usage:

int costs[4];

compute_costs(costs, q, ak, bk);
use_costs(costs);

👉 This is the most idiomatic C solution.

✅ 2. Return a pointer (with static array)
int *compute_costs(t_q *q, int ak, int bk)
{
    static int costs[4];

    costs[0] = ...;
    costs[1] = ...;
    costs[2] = ...;
    costs[3] = ...;

    return costs;
}

Usage:

int *costs = compute_costs(q, ak, bk);
use_costs(costs);

⚠️ Downsides:

Shared memory (overwritten on next call)
Not thread-safe
✅ 3. Dynamically allocate (malloc)
#include <stdlib.h>

int *compute_costs(t_q *q, int ak, int bk)
{
    int *costs = malloc(4 * sizeof(int));
    if (!costs)
        return NULL;

    costs[0] = ...;
    costs[1] = ...;
    costs[2] = ...;
    costs[3] = ...;

    return costs;
}

Usage:

int *costs = compute_costs(q, ak, bk);
use_costs(costs);
free(costs);
✅ 4. Use a struct (clean & expressive ⭐)
typedef struct s_costs
{
    int v[4];
} t_costs;

t_costs compute_costs(t_q *q, int ak, int bk)
{
    t_costs c;

    c.v[0] = ...;
    c.v[1] = ...;
    c.v[2] = ...;
    c.v[3] = ...;

    return c;
}

Usage:

t_costs costs = compute_costs(q, ak, bk);
use_costs(costs.v);
🏆 What you should use

For your case (push_swap-style logic):

👉 Use option 1 (pass array)

simplest
safest
fastest
no memory issues
⚡ Quick intuition
C doesn’t return arrays → you pass memory into the function
or wrap it in something (pointer / struct)

If you want, I can show how to combine this with your strategy selection function so everything is nicely modular.

just write the lines i need: the pass to function, the receiving function declaration, and how to get it

Here are exactly the lines you need 👇

✅ In main (or caller)
int costs[4];
compute_costs(costs, q, ak, bk);
use_costs(costs);
✅ Function declaration (prototype)
void compute_costs(int costs[4], t_q *q, int ak, int bk);
✅ Function definition
void compute_costs(int costs[4], t_q *q, int ak, int bk)
{
    costs[0] = ...;
    costs[1] = ...;
    costs[2] = ...;
    costs[3] = ...;
}
✅ Receiving in another function
void use_costs(int costs[4])
{
    int x = costs[0];  // access like normal array
}

That’s it—just pass the array, and every function can read/write it directly.

i want to add to this struct the directions and cost if necessary of the final combination found
struct s_coord
{
	t_node	*ak;
	t_node	*bk;
	int		ac;
	int		bc;
	int		totc;
	bool	adir;//false sx, true dx
	bool	bdir;
};

You’re already very close—your struct just needs to store which strategy was chosen and (optionally) the final computed cost.

Right now you have:

ac, bc → individual costs
adir, bdir → directions

What you’re missing is a clear way to represent the final combined move.

✅ Clean way to extend your struct

Add a strategy field and make totc the final cost:

typedef enum e_strategy
{
    RR,
    RRR,
    RA_RRB,
    RB_RRA
}   t_strategy;

struct s_coord
{
    t_node     *ak;
    t_node     *bk;
    int        ac;
    int        bc;
    int        totc;     // final chosen cost
    bool       adir;     // direction for A
    bool       bdir;     // direction for B
    t_strategy strat;    // which strategy was selected
};
✅ How you fill it

After computing your 4 cases:

int costs[4];

costs[RR]     = max(nrotcost(q, bk), nrotcost(q, ak));
costs[RRR]    = max(protcost(q, bk), protcost(q, ak));
costs[RA_RRB] = nrotcost(q, bk) + protcost(q, ak);
costs[RB_RRA] = protcost(q, bk) + nrotcost(q, ak);

Pick best:

int best = costs[0];
int best_strat = 0;

for (int i = 1; i < 4; i++)
{
    if (costs[i] < best)
    {
        best = costs[i];
        best_strat = i;
    }
}
✅ Store everything in your struct
coord->totc = best;
coord->strat = best_strat;
✅ Set directions based on strategy
if (coord->strat == RR)
{
    coord->adir = false;
    coord->bdir = false;
}
else if (coord->strat == RRR)
{
    coord->adir = true;
    coord->bdir = true;
}
else if (coord->strat == RA_RRB)
{
    coord->adir = false;
    coord->bdir = true;
}
else if (coord->strat == RB_RRA)
{
    coord->adir = true;
    coord->bdir = false;
}
⚡ Key idea
ac / bc → raw costs
strat → how to combine them
totc → final result after combination
adir / bdir → execution directions
💡 Small improvement (optional but nice)

Instead of bool, you could make directions clearer:

typedef enum e_dir
{
    UP,
    DOWN
} t_dir;

Then:

t_dir adir;
t_dir bdir;

If you want, I can help you collapse all of this into one function that directly returns a fully-filled s_coord—very clean for push_swap.

how should i add the enum enum e_strategy
{
    RR,     // both rotate up
    RRR,    // both rotate down
    RA_RRB, // a up, b down
    RB_RRA  // b up, a down
};
to the struct s_coord?

You just add it as a field in the struct using the enum type.

✅ Step 1: declare the enum (before the struct)
typedef enum e_strategy
{
    RR,
    RRR,
    RA_RRB,
    RB_RRA
}   t_strategy;
✅ Step 2: use it inside your struct
struct s_coord
{
    t_node     *ak;
    t_node     *bk;
    int        ac;
    int        bc;
    int        totc;
    bool       adir;
    bool       bdir;
    t_strategy strat;  // ← here
};
✅ Step 3: assign it
coord->strat = RR;
coord->strat = RRR;
coord->strat = RA_RRB;
coord->strat = RB_RRA;
✅ Step 4: use it
if (coord->strat == RR)
{
    // do rr
}
⚡ Key point
t_strategy becomes just another type like int
strat stores which combination won

If you want it even cleaner, you can later completely derive adir/bdir from strat and remove those booleans entirely.

is the enum not a different struct? is it just another struct?

Good instinct to question that—this is a key C concept.

👉 No, an enum is NOT a struct.
They are completely different things.

🔹 What an enum is

An enum is basically a set of named integer constants.

enum e_strategy
{
    RR,     // 0
    RRR,    // 1
    RA_RRB, // 2
    RB_RRA  // 3
};

So internally this is like:

RR = 0;
RRR = 1;
RA_RRB = 2;
RB_RRA = 3;

👉 It’s just an int with readable names.

🔹 What a struct is

A struct is a container of multiple variables:

struct s_coord
{
    int ac;
    int bc;
};

👉 It groups data together.

🔹 How they work together

When you do this:

t_strategy strat;

You’re just declaring a variable that can hold:

RR, RRR, RA_RRB, RB_RRA
🔹 In your struct
struct s_coord
{
    int        ac;
    int        bc;
    t_strategy strat;
};

👉 This means:

ac, bc → numbers
strat → one of your named options
🧠 Simple analogy
enum → like a menu choice
"RR", "RRR", etc.
struct → like a full order
includes food, drink, dessert (multiple fields)
⚡ Key takeaway
enum = named integer values
struct = group of variables
You store an enum inside a struct as a field

If you want, I can show you how to print the enum as a string ("RR", "RRR", etc.), which is super useful for debugging push_swap.

tell me the declaration needed for the enum and if i have to assign values apart from the name of the strategy and how to add the final value i want to store that comes from the enum

Here’s exactly what you need, clean and minimal 👇

✅ 1. Enum declaration
typedef enum e_strategy
{
    RR,
    RRR,
    RA_RRB,
    RB_RRA
}   t_strategy;

👉 That’s enough.
You do NOT need to assign values manually.

By default C does:

RR = 0
RRR = 1
RA_RRB = 2
RB_RRA = 3

(That’s perfect for indexing arrays too.)

✅ 2. Add it to your struct
struct s_coord
{
    t_node     *ak;
    t_node     *bk;
    int        ac;
    int        bc;
    int        totc;
    bool       adir;
    bool       bdir;
    t_strategy strat;
};
✅ 3. Store the result (this is what you asked)

After you find the best index:

int best_strat = 0; // result of your loop

Just assign:

coord->strat = best_strat;

👉 Works because best_strat is 0–3, same as enum values.

✅ 4. Or assign directly (if not using index)
coord->strat = RR;
coord->strat = RA_RRB;
✅ 5. Use it later
if (coord->strat == RRR)
{
    // do reverse rotations
}
⚡ Key idea
Enum = labels for integers
You store which case won
No extra value assignment needed
Your “final value” = just assign the winning index to strat

If you want next step: I can show you how to eliminate adir/bdir entirely and derive them from strat (cleaner design).

so if i am in a while loop and find the value corresponding to it, which will be an int between 0 and 3 will it be already evalyuated as an enum?

Yes — exactly 👍

In C, an enum value is just an int underneath, so if your loop gives you a value 0–3, it already matches your enum.

✅ What happens in your loop
int best_strat = 2;

Since your enum is:

RR = 0
RRR = 1
RA_RRB = 2
RB_RRA = 3

👉 2 is RA_RRB

✅ Assigning it
coord->strat = best_strat;

This works perfectly.

C does no conversion needed — it just stores the integer.

✅ Using it later
if (coord->strat == RA_RRB)
{
    // this will trigger if best_strat was 2
}
⚠️ Important nuance

C does not enforce enum safety.

This is technically allowed:

coord->strat = 42;  // ❌ still compiles

So your loop must guarantee:

0 <= best_strat <= 3
🧠 Mental model

Think of it like:

t_strategy strat = 2;   // same as RA_RRB

The enum just gives names to numbers, nothing more.

✅ Optional (cleaner style)

If you want to be explicit:

coord->strat = (t_strategy)best_strat;

Not required, but makes intent clearer.

⚡ Bottom line

✔ Your loop returning 0–3 is already compatible
✔ Assign directly → works
✔ Compare with enum names → works

If you want, next step is making a small helper like:

execute_strategy(coord);

so your main logic becomes super clean.