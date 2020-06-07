#include "tree_based_quadrants.h"

void
root (quadrant_t * q)
{
  q->level = 0;
  q->x = q->y = q->z = 0;
}


void
sibling(const quadrant_t* q, quadrant_t* sibling_quadrant, int sibling_id)
{
#if 0
	if (!is_valid(q)) {
		printf("sibling: the input quadrant has to be valid.\n");
		return;
	}
#endif
	if (sibling_id < 0 || sibling_id > 7) {
		printf
		("sibling: sibling_id should lie between 0 (included) \
        and 7 (included).\n");
		return;
	}

	sibling_quadrant->level = q->level;
	// we compute the size
	int h = QUADRANT_LEN(q->level);
	// compute parent coordinates
	sibling_quadrant->x = (sibling_id & 1) ? (q->x | h) : (q->x & ~h);
	sibling_quadrant->y = (sibling_id & 2) ? (q->y | h) : (q->y & ~h);
	sibling_quadrant->z = (sibling_id & 4) ? (q->z | h) : (q->z & ~h);
}

void
first_descendant(const quadrant_t* q, quadrant_t* first_descendant, int level)
{
#if 0
	if (!is_valid(q)) {
		printf("first_descendant: the input quadrant has to be valid.\n");
		return;
	}
#endif
	if ((int)q->level > level || level >= MAXLEVEL) {
		printf
		("first_descendant: level should lie between quadrant level (included) \
        and MAXLEVEL (excluded).\n");
		return;
	}

	first_descendant->x = q->x;
	first_descendant->y = q->y;
	first_descendant->z = q->z;

	first_descendant->level = (int8_t)level;
}


void
last_descendant (const quadrant_t * q, quadrant_t * last_descendant,
                 int level)
{
  qcoord_t            shift;

#if 0
  if (!is_valid (q)) {
    printf ("last_descendant: the input quadrant has to be valid.\n");
    return;
  }
#endif
  if ((int) q->level > level || level >= MAXLEVEL) {
    printf
      ("last_descendant: level should lie between quadrant level (included) \
        and MAXLEVEL (excluded).\n");
    return;
  }

  shift = QUADRANT_LEN (q->level) - QUADRANT_LEN (level);

  last_descendant->x = q->x + shift;
  last_descendant->y = q->y + shift;
  last_descendant->z = q->z + shift;

  last_descendant->level = (int8_t) level;
}
