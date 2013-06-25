#include "atto.h"

/**
 * Allocate a single-line style
 */
srule_t* srule_new_single(char* regex, int color, int bg_color, int is_bold) {
    srule_t* srule;
    srule = _srule_new(color, bg_color, is_bold);
    srule->type = ATTO_SRULE_TYPE_SINGLE;
    srule->regex_start = regex;
    return srule;
}

/**
 * Allocate a multi-line style
 */
srule_t* srule_new_multi(char* regex_start, char* regex_end, int color, int bg_color, int is_bold) {
    srule_t* srule;
    srule = _srule_new(color, bg_color, is_bold);
    srule->type = ATTO_SRULE_TYPE_MULTI;
    srule->regex_start = regex_start;
    srule->regex_end = regex_end;
    return srule;
}

/**
 * Allocate a range style
 */
srule_t* srule_new_range(mark_t* start, mark_t* end, int color, int bg_color, int is_bold) {
    srule_t* srule;
    srule = _srule_new(color, bg_color, is_bold);
    srule->type = ATTO_SRULE_TYPE_RANGE;
    srule->range_start = start;
    srule->range_end = end;
    return srule;
}

/**
 * Allocate a style
 */
srule_t* _srule_new(int color, int bg_color, int is_bold) {
    srule_t* srule;
    srule = (srule_t*)calloc(1, sizeof(srule_t));
    // TODO ncurses color pairs
    srule->color = color;
    srule->bg_color = bg_color;
    srule->is_bold = is_bold;
    return srule;
}

/**
 * Free a style
 */
int srule_destroy(srule_t* self) {
    // TODO pcre_free(self->regex_*)
    free(self);
    return ATTO_RC_OK;
}
