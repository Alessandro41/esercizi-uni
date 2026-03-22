package SMS;

import java.util.*;

public class SMSOrganizer {
    final private List<SMS> messages;

    public SMSOrganizer() {
        messages = new ArrayList<>();
    }

    public void addSMSToOrganizer(SMS sms) {
        this.messages.add(sms);
    }

    public List<SMS> getListByDate() {
        /* TODO */
        return this.messages;
    }

    public List<SMS> getListBySender() {
        /* TODO */
        return this.messages;
    }
}
