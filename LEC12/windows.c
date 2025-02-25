#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url)
{
    Location *loc = (Location *)malloc(sizeof(Location));
    loc->protocol = (char *)malloc(1);
    loc->protocol[0] = '\0';
    loc->host = (char *)malloc(1);
    loc->host[0] = '\0';
    loc->pathname = (char *)malloc(1);
    loc->pathname[0] = '\0';
    loc->search = (char *)malloc(1);
    loc->search[0] = '\0';
    loc->hash = (char *)malloc(1);
    loc->hash[0] = '\0';
    loc->port = 0;

    char *p = url;
    char *temp;

    // Remove trailing newline if any
    size_t url_len = strlen(url);
    if (url_len > 0 && url[url_len - 1] == '\n')
    {
        url[url_len - 1] = '\0';
    }

    // Parse protocol
    temp = strstr(p, "://");
    if (temp != NULL)
    {
        size_t len = temp - p;
        loc->protocol = (char *)realloc(loc->protocol, len + 1);
        strncpy(loc->protocol, p, len);
        loc->protocol[len] = '\0';
        p = temp + 3; // Move past "://"
    }

    // Parse host
    char *host_start = p;
    while (*p && *p != ':' && *p != '/' && *p != '?' && *p != '#')
    {
        p++;
    }
    size_t host_len = p - host_start;
    loc->host = (char *)realloc(loc->host, host_len + 1);
    strncpy(loc->host, host_start, host_len);
    loc->host[host_len] = '\0';

    // Parse port if any
    if (*p == ':')
    {
        p++; // Skip ':'
        char *port_start = p;
        while (*p && *p >= '0' && *p <= '9')
        {
            p++;
        }
        size_t port_len = p - port_start;
        char port_str[6] = {0};
        if (port_len < sizeof(port_str))
        {
            strncpy(port_str, port_start, port_len);
            port_str[port_len] = '\0';
            loc->port = atoi(port_str);
        }
    }

    // Parse pathname
    if (*p == '/')
    {
        p++; // Skip '/'
        char *path_start = p;
        while (*p && *p != '?' && *p != '#')
        {
            p++;
        }
        size_t path_len = p - path_start;
        loc->pathname = (char *)realloc(loc->pathname, path_len + 1);
        strncpy(loc->pathname, path_start, path_len);
        loc->pathname[path_len] = '\0';
    }

    // Parse search
    if (*p == '?')
    {
        p++; // Skip '?'
        char *search_start = p;
        while (*p && *p != '#')
        {
            p++;
        }
        size_t search_len = p - search_start;
        loc->search = (char *)realloc(loc->search, search_len + 1);
        strncpy(loc->search, search_start, search_len);
        loc->search[search_len] = '\0';
    }

    // Parse hash
    if (*p == '#')
    {
        p++; // Skip '#'
        char *hash_start = p;
        while (*p)
        {
            p++;
        }
        size_t hash_len = p - hash_start;
        loc->hash = (char *)realloc(loc->hash, hash_len + 1);
        strncpy(loc->hash, hash_start, hash_len);
        loc->hash[hash_len] = '\0';
    }

    return loc;
}