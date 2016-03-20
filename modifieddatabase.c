/* database.c */
/* Date  : 14 October 2015
 * Author: Sharang Gupta
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAXROWS 100
#define MAXDATA 512

typedef struct{
    int id, set;
    char name[MAXDATA], email[MAXDATA];
} address;

typedef struct{
    address rows[MAXROWS];
} *database;

typedef struct{
    database db;
    FILE *fp;
} *connection;

void die(char *message)
{
    if(errno) perror(message);
    else printf("ERROR: %s\n", message);
    exit(errno);
}

void pr_address(address *addr)
{
    printf("ID    : %d\n", addr->id);
    printf("NAME  : %s\n", addr->name);
    printf("EMAIL : %s\n", addr->email);
    putchar('\n');
}

void db_load(connection connt)
{
    fread(connt->db, sizeof(*connt->db), 1, connt->fp);
    if(feof(connt->fp) || ferror(connt->fp))
        die("failed to load database");
}

connection db_open(const char *filename, char mode)
{
    connection connt;

    if(!(connt = malloc(sizeof(*connt))) || !(connt->db = malloc(sizeof(*connt->db))))
        die("memory could not be allocated");

    if(!(connt->fp = fopen(filename, mode=='c' ? "wb" : "rb+")))
        die("failed to open file");

    if(mode!='c' && connt->fp) db_load(connt);

    return connt;
}

void db_close(connection connt)
{
    if(!connt) return;
    if(connt->fp) fclose(connt->fp);
    if(connt->db) free(connt->db);
    free(connt);
}

void db_write(connection connt)
{
    rewind(connt->fp);
    fwrite(connt->db, sizeof(*connt->db), 1, connt->fp);

    if(ferror(connt->fp))
        die("cannot write database into file");

    if(fflush(connt->fp))
        die("cannot flush database");
}

void db_create(connection connt)
{
    int i;

    for(i = 0; i<MAXROWS; ++i){
        connt->db->rows[i].id  = i;
        connt->db->rows[i].set = 0;
    }
}

void db_set(connection connt, int id, const char *name, const char *email)
{
    if(connt->db->rows[id].set)
        die("already set, delete first");

    strncpy(connt->db->rows[id].name , name , MAXDATA);
    strncpy(connt->db->rows[id].email, email, MAXDATA);
    connt->db->rows[id].set = 1;
}

void db_get(connection connt, int id)
{
    if(!connt->db->rows[id].set)
        die("address not set");
    pr_address(&connt->db->rows[id]);
}

void db_delete(connection connt, int id)
{
    connt->db->rows[id].set = 0;
}

void db_list(connection connt)
{
    int i;

    for(i = 0; i<MAXROWS; ++i)
        if(connt->db->rows[i].set)
            pr_address(&connt->db->rows[i]);
}

int main(int argc, char **argv)
{
    int id;
    connection connt;

    if(argc<3)
        die("USAGE: database <dbfile> <action> [action params]");

    connt = db_open(argv[1], argv[2][0]);


    if(argc>3) id = atoi(argv[3]);
    else id = 0;

    if(id>MAXROWS)
        die("requested id does not exist");

    switch(argv[2][0]){
    case 'c':
        db_create(connt);
        db_write (connt);
        break;

    case 'g':
        if(argc!=4)
            die("id required");
        db_get(connt, id);
        break;

    case 's':
        if(argc!=6)
            die("name, id, email required");
        db_set(connt, id, argv[4], argv[5]);
        db_write(connt);
        break;

    case 'd':
        if(argc!=4)
            die("id required");
        db_delete(connt, id);
        db_write(connt);
        break;

    case 'l':
        db_list(connt);
        break;

    default:
        die("invalid action! (c: create, g: get, s: set, d: del, l: list)");
        break;
    }

    db_close(connt);
    return 0;
}
/* end of database.c */
