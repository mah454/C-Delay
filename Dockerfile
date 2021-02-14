FROM empty:latest
MAINTAINER Mahdi Sheikh Hosseini <mah454>

COPY build/main /

ENTRYPOINT ["/main", "200"]
