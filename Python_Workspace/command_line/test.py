import sys
import time


def progressBar(it, prefix="", size=60):
    count = len(it)

    def _show(_i):
        x = int(size*_i/count)
        sys.stdout.write("%s[%s%s] %i/%i\r" %
                         (prefix, "#"*x, "."*(size-x), _i, count))
        sys.stdout.flush()

    _show(0)
    for i, item in enumerate(it):
        yield item
        _show(i + 1)
    sys.stdout.write('\n')
    sys.stdout.flush()


print("Downloading")
for i in progressBar(range(100), "", 40):
    time.sleep(0.01)
