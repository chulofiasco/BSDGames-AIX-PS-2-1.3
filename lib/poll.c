/* poll.c - bsd-games poll implementation using select() for AIX 1.3 */
#include <sys/poll.h>
#include <sys/select.h>
#include <sys/time.h>

int
poll(fds, nfds, timeout)
	struct pollfd *fds;
	unsigned int nfds;
	int timeout;
{
	fd_set rfds, wfds, efds;
	struct timeval tv, *tvp;
	int maxfd, ret, i;

	FD_ZERO(&rfds); FD_ZERO(&wfds); FD_ZERO(&efds);
	maxfd = -1;
	for (i = 0; i < (int)nfds; i++) {
		if (fds[i].fd < 0) continue;
		if (fds[i].events & (POLLIN|POLLPRI))
			FD_SET(fds[i].fd, &rfds);
		if (fds[i].events & POLLOUT)
			FD_SET(fds[i].fd, &wfds);
		FD_SET(fds[i].fd, &efds);
		if (fds[i].fd > maxfd) maxfd = fds[i].fd;
	}
	if (timeout == INFTIM) {
		tvp = (struct timeval *)0;
	} else {
		tv.tv_sec  = timeout / 1000;
		tv.tv_usec = (timeout % 1000) * 1000L;
		tvp = &tv;
	}
	ret = select(maxfd + 1, &rfds, &wfds, &efds, tvp);
	if (ret <= 0) return ret;
	for (i = 0; i < (int)nfds; i++) {
		fds[i].revents = 0;
		if (fds[i].fd < 0) continue;
		if (FD_ISSET(fds[i].fd, &rfds)) fds[i].revents |= POLLIN;
		if (FD_ISSET(fds[i].fd, &wfds)) fds[i].revents |= POLLOUT;
		if (FD_ISSET(fds[i].fd, &efds)) fds[i].revents |= POLLERR;
	}
	return ret;
}
